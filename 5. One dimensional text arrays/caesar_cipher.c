#include <stdio.h>
#include <stdlib.h>


int main() {
    printf("Podaj tekst:\n");
    char tekst [1000];
    int i;
    for (i = 0; i < 1000; i++)
    {
        scanf("%c", &tekst[i]);
        if (tekst[i] == '\n')
        {
            break;
        }
    }
    if (i == 1000)
    {
        while(getchar() != '\n'){}
        i -= 1;
    }
    printf("Podaj znak kodowy:\n");
    int kod;
    scanf("%d", &kod);
    for (int j = 0; j < i; j++) //pomenyal <=
    {
        if (tekst[j] >= 65 && tekst[j] <= 90)
        {
            int raz = ((tekst[j] - 65) + kod) % 26;
            if (tekst[j] + raz < 65)
            {
                tekst[j] = (tekst[j] + raz) + 25;
            }
            else
                tekst[j] = 65 + raz;
        }
        else if (tekst[j] >= 97 && tekst[j] <= 122)
        {
            int raz = ((tekst[j] - 97) + kod) % 26;
            if (tekst[j] + raz < 97)
            {
                tekst[j] = (97 + raz) + 25;
            }
            else
                tekst[j] = 97 + raz;
        }
        printf("%c", tekst[j]);
    }

    return 0;
}
