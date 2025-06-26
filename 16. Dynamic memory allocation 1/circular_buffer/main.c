#include <stdio.h>
#include "circular_buffer.h"
#include "tested_declarations.h"
#include "rdebug.h"
//#include "tested_declarations.h"
//#include "rdebug.h"
//#include "tested_declarations.h"
//#include "rdebug.h"
//#include "tested_declarations.h"
//#include "rdebug.h"

int main() {
    printf("Podaj rozmiar bufora:");
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
    struct circular_buffer_t* ukazatel;
    int prov = circular_buffer_create_struct(&ukazatel, size);
    if(prov == 2)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    int choose, number, ret;
    int err_code = 0;
    while(1)
    {
        printf("Co chcesz zrobic?");
        if (!scanf("%d", &choose))
        {
            printf("Incorrect input");
            circular_buffer_destroy_struct(&ukazatel);
            return 1;
        }
        err_code = 0;
        switch (choose){
            case 0:
                circular_buffer_destroy_struct(&ukazatel);
                return 0;
            case 1:
                printf("Podaj liczbe");
                if (!scanf("%d", &number))
                {
                    printf("Incorrect input");
                    circular_buffer_destroy_struct(&ukazatel);
                    return 1;
                }
                circular_buffer_push_back(ukazatel, number);
                break;
            case 2:
                ret = circular_buffer_pop_back(ukazatel, &err_code);
                if(err_code == 2)
                {
                    printf("Buffer is empty\n");
                    break;
                }

                printf("%d\n", ret);
                break;
            case 3:
                ret = circular_buffer_pop_front(ukazatel, &err_code);
                if(err_code == 2)
                {
                    printf("Buffer is empty\n");
                    break;
                }
                printf("%d\n", ret);
                break;
            case 4:
                if(circular_buffer_empty(ukazatel))
                {
                    printf("Buffer is empty\n");
                    break;
                }
                circular_buffer_display(ukazatel);
                printf("\n");
                break;
            case 5:
                printf("%d\n", circular_buffer_empty(ukazatel));
                break;
            case 6:
                printf("%d\n", circular_buffer_full(ukazatel));
                break;
            default:
                printf("Incorrect input data\n");
                break;
        }
    }
    return 0;
}




