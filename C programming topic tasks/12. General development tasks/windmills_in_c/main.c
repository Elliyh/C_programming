#include <stdio.h>
#include <stdlib.h>

enum Kierunek
{
 RIGHT,
 LEFT
};

void mini_r(int n, char **wiat)
{
    int row, col;
    for (row = 0; row < n; row++)
    {
        for(col = 0; col < n/2 && row < n/2; col++)
        {
            if (col < row+1)
            {
                *(*(wiat+row)+col) = 'X';
            }
            else
                break;
        }


        for (col = n/2; col < n && row < n/2; col++)
        {
            if (col < n-row)
            {
                *(*(wiat+row)+col) = 'X';
            }
        }

        for (col = 0; col < n / 2 && row >= n/2; col++) {
            if (col > n-(row+1))
            {
                *(*(wiat + row) + col) = 'X';
            }
        }


        for (col = n / 2; col < n && row >= n/2; col++) {
            if (col > row) {
                *(*(wiat + row) + col) = 'X';
            }
        }


    }

}




void mini_l(int n, char **wiat)
{
    int row, col;
    for (row = 0; row < n; row++)
    {
        for(col = 0; col < n/2 && row < n/2; col++)
        {
            if (col > row)
            {
                *(*(wiat+row)+col) = 'X';
            }
        }


        for (col = n/2; col < n && row < n/2; col++)
        {
            if (col > n-(row+1))
            {
                *(*(wiat+row)+col) = 'X';
            }
        }

        for (col = 0; col < n / 2 && row >= n/2; col++) {
            if (col < n-row)
            {
                *(*(wiat + row) + col) = 'X';
            }
        }


        for (col = n / 2; col < n && row >= n/2; col++) {
            if (col < row+1) {
                *(*(wiat + row) + col) = 'X';
            }
        }


    }

}



void wiatrak(int n, char **wiat, enum Kierunek k)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if (i == j || (n - 1)-j == i)
            {
                *(*(wiat+i)+j) = 'X';
                continue;
            }
            *(*(wiat+i)+j) = '?';
        }
    }



    if (k == RIGHT)
    {
        mini_r(n, wiat);
    }
    else
    {
        mini_l(n, wiat);
    }

    for (i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if (*(*(wiat+i)+j) == '?')
            {
                *(*(wiat+i)+j) = ' ';
            }
            printf("%c", *(*(wiat+i)+j));
        }
        printf("\n");
    }




}


int main() {
    int i, j;
    int massive [11] = {0};
    for (i = 0; i < 11; i++)
    {
        printf("Podaj liczbe:");
        if(!scanf("%d", &massive[i]))
        {
            return 0;
        }
        else if (massive[i] == 0)
            break;
        else if (massive[i] > 10 || massive[i] < -10)
        {
            return 0;
        }
    }
    if(i == 0)
    {
        return 0;
    }

    for (j = 0; j < i; j++)
    {
        enum Kierunek k = RIGHT;
        if (massive[j] < 0)
        {
            massive[j] *= -1;
            k = LEFT;
        }
        int n = massive[j] * 2;
        char **wiat = (char **)malloc(n * sizeof(char *));
        for (int row = 0; row < n; row++)
        {
            wiat[row] = (char *)malloc(n * sizeof(char));
        }
        char** ukaz = (char **) wiat;
        wiatrak(n, ukaz, k);
        printf("\n");
    }
    return 0;
}
