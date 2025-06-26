#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dictionary.h"
#include <ctype.h>
#include "tested_declarations.h"
#include "rdebug.h"

//#include "tested_declarations.h"
//#include "rdebug.h"



int main() {
    char* filename = calloc(50, sizeof(char));
    if(filename == NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    printf("Podaj nazwę pliku:");
    scanf("%49[^\n]", filename);
    FILE *f = fopen(filename, "r");
    if(f == NULL)
    {
        free(filename);
        printf("Couldn't open file");
        return 4;
    }
    free(filename);
    char* word = calloc(50, sizeof(char));
    if(word == NULL)
    {
        fclose(f);
        printf("Failed to allocate memory");
        return 8;
    }
    struct dictionary_t* ukaz;
    int err_code = 0;
    ukaz = create_dictionary(10, &err_code);
    if(ukaz == NULL)
    {
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
    while (fscanf(f, "%49[^,.!;: ]", word) == 1 && !feof(f))
    {
        //printf("%s\n", word);
        int prov = dictionary_add_word(ukaz, word);
        if(prov == 2)
        {
            printf("Failed to allocate memory");
            destroy_dictionary(&ukaz);
            free(word);
            fclose(f);
            return 8;
        }
        c = fgetc(f);
        while(!isalpha(c) && !feof(f))
        {
            c = fgetc(f);
        }
        ungetc(c, f);
    }
    if(ukaz->size == 0)
        printf("Nothing to show");
    else
        dictionary_display(ukaz);
    destroy_dictionary(&ukaz);
    fclose(f);
    free(word);
    return 0;
}




