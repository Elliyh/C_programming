#include <stdio.h>
#include <string.h>
#include "tested_declarations.h"
#include "rdebug.h"


void swap(char **a, char **b)
{

    //char *temp = *a;
    //*a = *b;
    //*b = temp;
    //printf("%s %s\n\n", a, b);
    char temp[1000];  // Временный буфер для сохранения содержимого
    strcpy(temp, (const char *) a);
    strcpy((char *) a, (const char *) b);
    strcpy((char *) b, temp);
    //char *temp = *a;
    //printf("%s %s\n\n", a, b);
    //*a = *b;
    //*b = temp;
}


int sort_alphabetically(char tab[])
{
    int spr = 0;
    while (*(tab+spr) != '\0')
    {
        if (*(tab+spr) == '\'' || *(tab+spr) == '\n' || *(tab+spr) == '\"' || *(tab+spr) == ',' || *(tab+spr) == '.')
            return 1;
        spr++;
    }

    if (tab == NULL || *tab == '\0')
        return 1;
    char new_massive [500][1000] = {'\0'};
    char* token = strtok(tab, " ");
    int i = 0;
    while (token != NULL)
    {
        strcpy(*(new_massive+i), token);
        token = strtok(NULL, " ");
        i++;
    }

    int g;
    for (g = 0; g < i-1; g++)
    {
        for(int j = 0; j < i-g-1; j++)
        {
            int k = 0;
            while (*(*(new_massive+j)+k) == *(*(new_massive+j+1)+k) && *(*(new_massive+j)+k) != '\0')
            {
                if (*(*(new_massive+j)+k) > *(*(new_massive+j+1)+k))
                {
                    swap((char **) (new_massive + j), (char **) (new_massive + j + 1));
                }
                k++;
            }
            if (*(*(new_massive+j)+k) > *(*(new_massive+j+1)+k))
                swap((char **) (new_massive + j), (char **) (new_massive + j + 1));


        }
    }

    int l = 0;
    for (g = 0; g < i; g++)
    {
        if (*(*(new_massive+g)) == '\0')
            break;
        for (int k = 0; k < 1000 && *(*(new_massive+g)+k) != '\0'; k++)
        {
            *(tab+l) = *(*(new_massive+g)+k);
            l++;
        }
        *(tab+l) = ' ';
        l++;
    }
    *(tab+l-1) = '\0';

    return 0;
}



int main() {
    /*char input[] = "bosom";

    printf("#####START#####");
    int res = sort_alphabetically(input);
    printf("#####END#####");

    //test_error(res == 0, "Funkcja sort_alphabetically() zwróciła niepoprawną wartość, powinna zwrócić 0, a zwróciła %d", res);

    //if (!0)
        //test_error(strcmp(input, "bosom") == 0, "Funkcja sort_alphabetically() niepoprawnie posortowała tablicę, powinno być 'bosom', a jest %s", input);*/

    printf("Podaj tekst:\n");
    char tekst [1001] = {'\0'};
    scanf("%1000[^\n]", tekst);


    int spraw = sort_alphabetically(tekst);

    if (spraw == 1)
    {
        printf("incorrect input data");
        return 2;
    }

    printf("%s", tekst);




    return 0;
}
