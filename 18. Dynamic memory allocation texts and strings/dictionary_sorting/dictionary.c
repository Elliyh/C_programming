#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"
#include "tested_declarations.h"
#include "rdebug.h"



struct dictionary_t* create_dictionary(int N, int *err_code)
{
    if(err_code != NULL)
    {
        *err_code = 0;
    }
    if(N <= 0)
    {
        if(err_code != NULL)
        {
            *err_code = 1;
        }
        return NULL;
    }
    struct dictionary_t* dictionary = calloc(1, sizeof(struct dictionary_t));
    if(dictionary == NULL)
    {
        if(err_code != NULL)
        {
            *err_code = 2;
        }
        return NULL;
    }
    dictionary->wc = calloc(N, sizeof(struct word_count_t));
    if(dictionary->wc == NULL)
    {
        free(dictionary);
        if(err_code != NULL)
        {
            *err_code = 2;
        }
        return NULL;
    }
    dictionary->capacity = N;
    dictionary->size = 0;
    if(err_code != NULL)
    {
        *err_code = 0;
    }
    return dictionary;
}

void destroy_dictionary(struct dictionary_t** d)
{
    if(d == NULL || *d == NULL)
        return;
    for(int i = 0; i < (*d)->size; i++)
    {
        if(((*d)->wc+i)->word != NULL)
        {
            free(((*d)->wc+i)->word);
        }
    }
    free((*d)->wc);
    free(*d);
    *d = NULL;
}

struct word_count_t* dictionary_find_word(const struct dictionary_t *d, const char *word)
{
    if(d == NULL || word == NULL || d->wc == NULL || d->size <= 0 || d->capacity <= 0
    || d->size > d->capacity)
    {
        return NULL;
    }
    int i;
    for(i = 0; i < d->size; i++)
    {
        if(strcmp(word, (d->wc+i)->word) == 0 )
            return d->wc+i;
    }
    return NULL;
}

void dictionary_display(const struct dictionary_t *d)
{
    if(d == NULL || d->size < 0 || d->capacity <= 0 || d->size > d->capacity|| d->wc == NULL)
        return;
    int i;
    for(i = 0; i < d->size; i++)
    {
        printf("%s %d\n", (d->wc+i)->word, (d->wc+i)->counter);
    }
}

int dictionary_add_word(struct dictionary_t *d, const char *word)
{
    if(d == NULL || word == NULL || d->wc == NULL || d->size < 0 || d->capacity <= 0
       || d->size > d->capacity)
    {
        return 1;
    }
    int i;
    for(i = 0; i < d->size; i++)
    {
        if(strcmp(word, (d->wc+i)->word) == 0 )
        {
            (d->wc+i)->counter += 1;
            return 0;
        }
    }
    if(d->size == d->capacity)
    {
        struct word_count_t* new = realloc(d->wc, d->capacity*2*sizeof(struct word_count_t));
        if(new == NULL)
        {
            return 2;
        }
        d->wc = new;
        d->capacity = d->capacity * 2;
    }
    (d->wc+(d->size))->counter = 1;
    (d->wc+(d->size))->word = calloc(strlen(word)+1, sizeof(char));
    if((d->wc+(d->size))->word == NULL)
        return 2;
    strcpy((d->wc+(d->size))->word, word);
    d->size += 1;
    return 0;
}

int dictionary_sort_alphabetically(struct dictionary_t *d){
    if(d == NULL || d->size < 0 || d->capacity <= 0 || d->size > d->capacity|| d->wc == NULL)
        return 1;
    for(int i = 0; i < d->size-1; i++)
    {
        for(int j = 0; j < d->size - i - 1; j++)
        {
            if(strcmp((d->wc+j)->word, (d->wc+j+1)->word) >0 )
            {
                //printf("%s %s\n", (d->wc+j)->word, (d->wc+j+1)->word);
                struct word_count_t temp = *(d->wc + j);
                *(d->wc + j) = *(d->wc + j + 1);
                *(d->wc + j + 1) = temp;
                //printf("%s %s\n\n", (d->wc+j)->word, (d->wc+j+1)->word);
            }
        }
    }
    return 0;
}

int dictionary_sort_occurence(struct dictionary_t *d)
{
    if(d == NULL || d->size < 0 || d->capacity <= 0 || d->size > d->capacity|| d->wc == NULL)
        return 1;
    for(int i = 0; i < d->size-1; i++)
    {
        for(int j = 0; j < d->size - i - 1; j++)
        {
            if((d->wc+j)->counter < (d->wc+j+1)->counter)
            {
                struct word_count_t temp = *(d->wc + j);
                *(d->wc + j) = *(d->wc + j + 1);
                *(d->wc + j + 1) = temp;
            }
        }
    }


    for(int i = 0; i < d->size-1; i++)
    {
        for(int j = 0; j < d->size - 1; j++)
        {
            if((d->wc+j)->counter  == (d->wc+j+1)->counter)
            {
                if(strcmp((d->wc+j)->word, (d->wc+j+1)->word) > 0 )
                {
                    //printf("%s %s\n", (d->wc+j)->word, (d->wc+j+1)->word);
                    struct word_count_t temp = *(d->wc + j);
                    *(d->wc + j) = *(d->wc + j + 1);
                    *(d->wc + j + 1) = temp;
                    //printf("%s %s\n\n", (d->wc+j)->word, (d->wc+j+1)->word);
                }
            }
        }
    }
    return 0;
}

int save_dictionary_b(const struct dictionary_t *d, const char *filename)
{
    if(d == NULL || d->size <= 0 || d->capacity <= 0 || d->size > d->capacity|| d->wc == NULL
    || filename == NULL)
        return 1;
    FILE *f = fopen(filename, "wb");
    if(f == NULL)
        return 2;

    fwrite(&d->size, sizeof(int), 1, f);
    for(int i = 0; i < d->size; i++)
    {
        int len = strlen((d->wc+i)->word);
        fwrite(&len, sizeof(int), 1, f);
        fwrite((d->wc+i)->word, sizeof(char), strlen((d->wc+i)->word), f);
        fwrite(&(d->wc+i)->counter, sizeof(int), 1, f);
    }
    fclose(f);
    return 0;
}

struct dictionary_t* load_dictionary_b(const char *filename, int *err_code)
{
    if(filename == NULL)
    {
        if(err_code != NULL)
            *err_code = 1;
        return NULL;
    }
    if(err_code != NULL)
        *err_code = 0;
    FILE *f = fopen(filename, "rb");
    if(f == NULL)
    {
        if(err_code != NULL)
            *err_code = 2;
        return NULL;
    }
    int size;
    fread(&size, sizeof(int), 1, f);
    if(size <= 0)
    {
        if(err_code != NULL)
            *err_code = 3;
        fclose(f);
        return NULL;
    }
    int prov = 0;
    struct dictionary_t* d = create_dictionary(size, &prov);
    if (d == NULL || prov == 2)
    {
        if(err_code != NULL)
            *err_code = 4;
        fclose(f);
        return NULL;
    }
    d->capacity = size;
    int len_word, counter_word;
    for(int i = 0; i < size; i++)
    {
        if(fread(&len_word, sizeof(int), 1, f) != 1)
        {
            if(err_code != NULL)
                *err_code = 3;
            destroy_dictionary(&d);
            fclose(f);
            return NULL;
        }

        if(len_word <= 0)
        {
            if(err_code != NULL)
                *err_code = 3;
            destroy_dictionary(&d);
            fclose(f);
            return NULL;
        }


        (d->wc+i)->word = calloc(len_word+1, sizeof(char));
        if((d->wc+i)->word == NULL)
        {
            if(err_code != NULL)
                *err_code = 4;
            destroy_dictionary(&d);
            fclose(f);
            return NULL;
        }


        if(fread((d->wc+i)->word, sizeof(char), len_word, f) != (long unsigned int)len_word)
        {
            if(err_code != NULL)
                *err_code = 3;
            destroy_dictionary(&d);
            fclose(f);
            return NULL;
        }


        if(fread(&counter_word, sizeof(int), 1, f) != 1)
        {
            if(err_code != NULL)
                *err_code = 3;
            destroy_dictionary(&d);
            fclose(f);
            return NULL;
        }
        if(counter_word <= 0)
        {
            if(err_code != NULL)
                *err_code = 3;
            destroy_dictionary(&d);
            fclose(f);
            return NULL;
        }
        (d->wc+i)->counter = counter_word;
        d->size++;
    }
    fclose(f);
    return d;
}



