#include <stdio.h>
#include "image_utils.h"
#include <string.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

int main() {
    char* filename = (char*)calloc(40, sizeof(char));
    if(filename == NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    printf("Enter destination image file name:");
    scanf("%39s", filename);
    while(getchar() != '\n'){}
    int error;
    struct image_t * obraz;
    obraz = load_image_t(filename, &error);
    if(obraz == NULL)
    {
        switch (error)
        {
            case 2:
                printf("Couldn't open file");
                free(filename);
                return 4;
            case 3:
                printf("File corrupted");
                free(filename);
                return 6;
            case 4:
                printf("Failed to allocate memory");
                free(filename);
                return 8;
        }

    }
    struct rectangle_t* figura = malloc(sizeof(struct rectangle_t));
    if(figura == NULL)
    {
        destroy_image(&obraz);
        free(filename);
        printf("Failed to allocate memory");
        return 8;
    }
    //*(figura->p) = malloc(sizeof(struct point_t));
    printf("Podaj wspolrzedne i wymiary prostokata:");
    int value;

    if(scanf("%d %d %d %d", &figura->p.x, &figura->p.y, &figura->width, &figura->height) != 4)
    {
        printf("Incorrect input");
        destroy_image(&obraz);
        free(filename);
        free(figura);
        return 1;
    }
    printf("Podaj kolor:");
    if(scanf("%d", &value) != 1)
    {
        printf("Incorrect input");
        destroy_image(&obraz);
        free(figura);
        free(filename);
        return 1;
    }

    if(figura->p.x < 0 || figura->p.y < 0 || figura->width <= 0 || figura->height <= 0
       || figura->height + figura->p.y > obraz->height || figura->width + figura->p.x > obraz->width || value > 255 || value < 0)
    {
        printf("Incorrect input data");
        destroy_image(&obraz);
        free(figura);
        free(filename);
        return 2;
    }
    image_draw_rectangle(obraz, figura, value);
    error = save_image_t(filename, obraz);
    if(error != 0)
    {
        printf("Couldn't create file");
        free(filename);
        free(figura);
        destroy_image(&obraz);
        return 5;
    }
    if(filename != NULL) free(filename);
    destroy_image(&obraz);
    free(figura);
    printf("File saved");
    return 0;
}

