#include <stdio.h>
#include "array.h"
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"
//#include "tested_declarations.h"
//#include "rdebug.h"


int main() {
    printf("Podaj pojemność tablicy: ");
    int size;
    if(!scanf("%d", &size))
    {
        printf("Incorrect input");
        return 1;
    }
    if(size <= 0)
    {
        printf("Incorrect input data");
        return 2;
    }
    struct array_t **my_struct = malloc(sizeof(struct array_t));
    int spraw = array_create_struct(my_struct, size);
    if(spraw == 2 || spraw == 1)
    {
        printf("Failed to allocate memory");
        free(my_struct);
        array_destroy_struct(my_struct);
        return 8;
    }
    while(1)
    {
        int chose, i, digit;;
        printf("Co chcesz zrobic: ");
        if(!scanf("%d", &chose))
        {
            printf("Incorrect input");
            while(getchar() != '\n'){}
            free(my_struct);
            array_destroy_struct(my_struct);
            return 1;
        }
        if(chose == 0)
            break;
        switch (chose)
        {
            case 1:
                printf("Podaj liczby do zapisania: ");
                for(i = 0; i <= (*my_struct)->capacity; i++)
                {
                    if(!scanf("%d", &digit))
                    {
                        printf("Incorrect input");
                        free(my_struct);
                        array_destroy_struct(my_struct);
                        return 1;
                    }
                    if(digit == 0)
                        break;
                    if(array_push_back(*(my_struct), digit) == 2)
                    {
                        printf("Buffer is full\n");
                        break;
                    }
                }
                array_display(*my_struct);
                printf("\n");
                while(getchar() != '\n'){}
                break;
            case 2:
                printf("Podaj kolejne liczby, które mają zostać usuniete z tablicy: ");
                for(i = 0;; i++)
                {
                    if(!scanf("%d", &digit))
                    {
                        printf("Incorrect input");
                        free(my_struct);
                        array_destroy_struct(my_struct);
                        return 1;
                    }
                    if(digit == 0)
                    {
                        if((*my_struct)->size == 0)
                        {
                            break;
                        }
                        break;
                    }

                    spraw = array_remove_item(*(my_struct), digit);
                    if((*my_struct)->size == 0)
                    {
                        break;
                    }
                }
                if((*my_struct)->size == 0)
                {
                    printf("Buffer is empty\n");
                    while(getchar() != '\n'){}
                    break;
                }
                array_display(*my_struct);
                printf("\n");
                while(getchar() != '\n'){}
                break;

            default:
                while(getchar() != '\n'){}
                printf("Incorrect input data\n");
        }
    }
    array_destroy_struct(my_struct);
    free(my_struct);
    return 0;
}



