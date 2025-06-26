#include <stdio.h>
#include "vector.h"
#include "tested_declarations.h"
#include "rdebug.h"

int main() {
    printf("Podaj pojemność tablicy:\n");
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
    struct vector_t* ukaz;
    int check = vector_create_struct(&ukaz, size);
    if(check == 2)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    while(1)
    {
        printf("Co chcesz zrobic:");
        int choose;
        if(!scanf("%d", &choose))
        {
            printf("Incorrect input");
            vector_destroy_struct(&ukaz);
            return 1;
        }
        switch (choose)
        {
            case 0:
                vector_destroy_struct(&ukaz);
                return 0;
            case 1:
                printf("Podaj kolejne liczby, które mają zostać dodane do tablicy:");
                while(1)
                {
                    int number;
                    if(!scanf("%d", &number))
                    {
                        printf("\nIncorrect input");
                        vector_destroy_struct(&ukaz);
                        return 1;
                    }
                    if(number == 0)
                        break;
                    int spraw = vector_push_back(ukaz, number);
                    if(spraw == 2)
                    {
                        printf("Failed to allocate memory\n");
                        break;
                    }

                }
                vector_display(ukaz);
                printf("\n");
                break;
            case 2:
                printf("Podaj kolejne liczby, które mają zostać usuniete z tablicy:");
                while(1)
                {
                    int number;
                    if(!scanf("%d", &number))
                    {
                        printf("\nIncorrect input");
                        vector_destroy_struct(&ukaz);
                        return 1;
                    }
                    if(number == 0) {
                        if(ukaz->size == 0)
                        {
                            printf("Buffer is empty");
                            break;
                        }
                        break;
                    }

                    int spraw = vector_erase(ukaz, number);
                    if(spraw == -1)
                    {
                        printf("\nFailed to allocate memory");
                        break;
                    }

                }
                vector_display(ukaz);
                printf("\n");
                break;
            default:
                printf("Incorrect input data\n");
        }
    }
    return 0;
}



