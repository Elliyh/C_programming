#include <stdio.h>
#include "array.h"
#include "tested_declarations.h"
#include "rdebug.h"
//#include "tested_declarations.h"
//#include "rdebug.h"


int main() {
    printf("Podaj rozmiar tablicy: ");
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
    struct array_t my_array;
    if(array_create(&my_array, size) == 2)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    int i, digit;
    printf("Podaj liczby do zapisania:\n");
    for(i = 0; i <= my_array.capacity; i++)
    {
        if(!scanf("%d", &digit))
        {
            printf("Incorrect input");
            array_destroy(&my_array);
            return 1;
        }
        if(digit == 0)
            break;
        if(array_push_back(&my_array, digit) == 2)
        {
            printf("Buffer is full\n");
            break;
        }
    }
    array_display(&my_array);
    if(my_array.size == 0)
    {
        printf("Buffer is empty");
    }
    array_destroy(&my_array);
    return 0;
}


