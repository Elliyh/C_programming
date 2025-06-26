#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"
#include "tested_declarations.h"
#include "rdebug.h"


//#include "tested_declarations.h"
//#include "rdebug.h"

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



