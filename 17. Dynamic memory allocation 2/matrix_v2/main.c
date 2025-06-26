#include <stdio.h>
#include <stdlib.h>
#include "matrix_utils.h"
#include <string.h>
#include "tested_declarations.h"
#include "rdebug.h"






int main() {
    printf("Podaj szerokość i wysokość:");
    int width, height;
    if(scanf("%d %d", &width, &height) != 2)
    {
        printf("incorrect input");
        return 1;
    }
    if(height<= 0 || width <= 0)
    {
        printf("incorrect input data");
        return 2;

    }
    struct matrix_t* ukaz = matrix_create_struct(width, height);
    if(ukaz == NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    printf("Podaj liczby:");
    int prov = matrix_read(ukaz);
    if(prov ==  2)
    {
        printf("incorrect input");
        matrix_destroy_struct(&ukaz);
        return 1;
    }



    char *filename = malloc(40*sizeof(char));
    if(filename == NULL)
    {
        printf("failed to allocate memory");
        matrix_destroy_struct(&ukaz);
        return 8;
    }

    for(int i = 0; i < 40; i++)
    {
        *(filename+i) = '\0';
    }
    printf("Podaj sciezke do pliku:\n");
    while(getchar() != '\n'){}
    if(!scanf("%39[^\n]", filename))
    {
        printf("incorrect input");
        matrix_destroy_struct(&ukaz);
        free(filename);
        return 1;
    }
    struct matrix_t* new_ukaz = matrix_transpose(ukaz);
    if(new_ukaz == NULL){
        printf("failed to allocate memory");
        matrix_destroy_struct(&ukaz);
        free(filename);
        return 8;
    }

    if((*(filename+ strlen(filename)-1) != 'n' && *(filename+ strlen(filename)-2) != 'i'&& *(filename+ strlen(filename)-3) != 'b' && *(filename+ strlen(filename)-4) != '.')
       || (*(filename+ strlen(filename)-1) != 't' && *(filename+ strlen(filename)-2) != 'x'&& *(filename+ strlen(filename)-3) != 't' && *(filename+ strlen(filename)-4) != '.'))
    {
        printf("Unsupported file format");
        matrix_destroy_struct(&ukaz);
        matrix_destroy_struct(&new_ukaz);
        free(filename);
        return 7;
    }
    if(*(filename+ strlen(filename)-1) == 'n' && *(filename+ strlen(filename)-2) == 'i'&& *(filename+ strlen(filename)-3) == 'b' && *(filename+ strlen(filename)-4) == '.')
    {
        prov = matrix_save_b(new_ukaz, filename);
    }
    else if(*(filename+ strlen(filename)-1) == 't' && *(filename+ strlen(filename)-2) == 'x'&& *(filename+ strlen(filename)-3) == 't' && *(filename+ strlen(filename)-4) == '.')
    {
        prov = matrix_save_t(new_ukaz, filename);
    }
    if(prov == 2 || prov == 3)
    {
        printf("Couldn't create file");
        free(filename);
        matrix_destroy_struct(&ukaz);
        matrix_destroy_struct(&new_ukaz);
        return 5;
    }
    printf("File saved");
    free(filename);
    matrix_destroy_struct(&ukaz);
    matrix_destroy_struct(&new_ukaz);
    return 0;
}
/*
 3
-9
-9
-2
-10
-9
-4
-7
-8
10
0
5
-7
4
3
 */



