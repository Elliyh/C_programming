#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dictionary.h"
#include <ctype.h>
#include "tested_declarations.h"
#include "rdebug.h"



int main() {
    char* filename = calloc(40, sizeof(char));
    if(filename == NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    printf("Podaj nazwę pliku:");
    scanf("%49[^\n]", filename);
    int mode;
    printf("Co chcesz teraz zrobić:");
    if(!scanf("%d", &mode))
    {
        printf("Incorrect input");
        free(filename);
        return 1;
    }
    if(mode != 0 && mode != 1)

    {
        printf("Incorrect input data");
        free(filename);
        return 2;
    }
    struct dictionary_t* ukaz;
    if (mode == 1)
    {
        FILE *f = fopen(filename, "r");
        if(f == NULL)
        {
            free(filename);
            printf("Couldn't open file");
            return 4;
        }
        //free(filename);
        char* word = calloc(40, sizeof(char));
        if(word == NULL)
        {
            free(filename);
            fclose(f);
            printf("Failed to allocate memory");
            return 8;
        }
        int err_code = 0;
        ukaz = create_dictionary(10, &err_code);
        if(ukaz == NULL)
        {
            free(filename);
            fclose(f);
            free(word);
            printf("Failed to allocate memory");
            return 8;
        }
        char c = fgetc(f);
        while(!isalpha(c) && !feof(f))
        {
            c = fgetc(f);
        }
        ungetc(c, f);
        while (fscanf(f, "%49[^,.!;: ]", word) == 1)
        {
            //printf("%s\n", word);
            int prov = dictionary_add_word(ukaz, word);
            if(prov == 2)
            {
                printf("Failed to allocate memory");
                destroy_dictionary(&ukaz);
                free(word);
                fclose(f);
                free(filename);
                return 8;
            }
            c = fgetc(f);
            while(!isalpha(c) && !feof(f))
            {
                c = fgetc(f);
            }
            ungetc(c, f);
        }
        free(word);
        fclose(f);
    }
    else
    {
        int err_code;
        ukaz = load_dictionary_b(filename, &err_code);
        if(err_code == 2)
        {
            free(filename);
            printf("Couldn't open file");
            return 4;
        }
        else if(err_code == 3)
        {
            free(filename);
            printf("File corrupted");
            return 6;
        }
        else if (err_code == 4)
        {
            free(filename);
            printf("Failed to allocate memory");
            return 8;
        }
    }
    char* filename_alpha = calloc(strlen(filename)+7, sizeof(char));
    if(filename_alpha == NULL)
    {
        free(filename);
        destroy_dictionary(&ukaz);
        printf("Failed to allocate memory");
        return 8;
    }
    char* filename_occ = calloc(strlen(filename)+5, sizeof(char));
    if(filename_occ == NULL)
    {
        free(filename);
        free(filename_alpha);
        destroy_dictionary(&ukaz);
        printf("Failed to allocate memory");
        return 8;
    }
    strncpy(filename_alpha, filename, strlen(filename)-4);
    strncpy(filename_occ, filename, strlen(filename)-4);
    if(*(filename+strlen(filename) - 1) == 't')
    {
        strcat(filename_alpha, "_alpha.txt");
        strcat(filename_occ, "_occ.txt");
    }
    else
    {
        strcat(filename_alpha, "_alpha.bin");
        strcat(filename_occ, "_occ.bin");
    }


    dictionary_sort_alphabetically(ukaz);
    int prov = save_dictionary_b(ukaz, filename_alpha);
    if(prov != 0)
    {
        printf("Couldn't create file\n");
    }
    else
    {
        printf("File saved\n");
    }
    dictionary_sort_occurence(ukaz);
    prov = save_dictionary_b(ukaz, filename_occ);
    if(prov != 0)
    {
        printf("Couldn't create file");
    }
    else
    {
        printf("File saved");
    }
    /*if(ukaz->size == 0)
        printf("Nothing to show");
    else
        dictionary_display(ukaz);
    destroy_dictionary(&ukaz);*/
    free(filename);
    free(filename_alpha);
    free(filename_occ);
    destroy_dictionary(&ukaz);
    return 0;
}




