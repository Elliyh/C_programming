#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"
//#include "tested_declarations.h"
//#include "rdebug.h"





int main() {
    char* text = NULL;
    char c;
    int count = 0;


    char* temp = realloc(text, 50*(1+count/50));
    if(temp == NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    printf("Podaj tekst:");
    text = temp;
    int flag = 0;
    while ((c = getchar()) != '\n')
    {
        *(text+count) = c;
        count++;
        if(count%50 == 0)
        {
            char* new = realloc(text, 50*(1+count/50));
            if(new == NULL)
            {
                flag = 1;
                *(text+count-1) ='\0';
                break;
            }
            text = new;
        }
    }

    if(flag == 0)
        *(text+count) = '\0';
    printf("%s", text);
    free(text);
    return 0;
}




