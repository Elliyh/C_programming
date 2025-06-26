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
    int count;
    printf("How many subimages you want to draw:");
    if(!scanf("%d", &count))
    {
        printf("Incorrect input");
        destroy_image(&obraz);
        free(filename);
        return 1;
    }
    if(count <= 0)
    {
        printf("Incorrect input data");
        destroy_image(&obraz);
        free(filename);
        return 2;
    }
    char* new_filename = (char*)malloc(40*sizeof(char));
    if(new_filename == NULL)
    {
        printf("Failed to allocate memory");
        destroy_image(&obraz);
        free(filename);
        return 8;
    }
    int i;
    for(i = 0; i < count; i++)
    {
        printf("Enter a name of a subimage: ");
        scanf("%39s", new_filename);
        struct image_t* new_obraz;
        new_obraz = load_image_t(new_filename, &error);
        if(new_obraz == NULL)
        {
            switch (error)
            {
                case 2:
                    printf("Couldn't open file\n");
                    //free(new_filename);
                    //free(filename);
                    continue;
                case 3:
                    printf("File corrupted\n");
                    //free(new_filename);
                    //free(filename);
                    continue;
                case 4:
                    printf("Failed to allocate memory");
                    free(new_filename);
                    free(filename);
                    return 8;
            }
        }
        printf("Enter coordinates (x, y):");
        int x, y;
        if(scanf("%d %d", &x, &y) != 2)
        {
            printf("Incorrect input");
            destroy_image(&obraz);
            destroy_image(&new_obraz);
            free(new_filename);
            free(filename);
            return 1;
        }
        if(x < 0 || y <  0 )
        {
            printf("Incorrect input data\n");
            destroy_image(&new_obraz);
            continue;
        }
        error = draw_image(obraz, new_obraz, x, y);
        if(error == 1)
        {
            printf("Incorrect input data\n");
        }
        destroy_image(&new_obraz);
    }
    char* modified_name = (char*)calloc(49, sizeof(char));
    i = (int)strlen(filename)-1;
    char a, b, c;
    a = *(filename+strlen(filename)-1);
    b = *(filename+strlen(filename)-2);
    c = *(filename+strlen(filename)-3);
    while(*(filename+i) != '.')
    {
        *(filename+i) = '\0';
        i--;
    }
    *(filename+i) = '\0';
    snprintf(modified_name, 49, "%s_modified.%c%c%c", filename, a, b, c);
    error = save_image_t(modified_name, obraz);
    if(error != 0)
    {
        printf("Couldn't create file");
        free(modified_name);
        destroy_image(&obraz);
        free(new_filename);
        free(filename);
        return 5;
    }
    if(modified_name != NULL) free(modified_name);
    destroy_image(&obraz);
    if(filename != NULL)free(filename); //
    if(new_filename != NULL)free(new_filename);  //
    printf("File saved");

    return 0;
}


