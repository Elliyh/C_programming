#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tested_declarations.h"
#include "rdebug.h"
//#include "tested_declarations.h"
//#include "rdebug.h"


int split_sentences(const char *text, char ****output);
int sort_sentences(char ***output);
void destroy(char ***words);
void display(char ***words);


int main() {
    char* text = malloc(1000*sizeof(char));
    if(text == NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    printf("Enter text:");
    for(int i = 0; i < 1000; i++)
    {
        *(text+i) = '\0';
    }
    scanf("%999[^\n]", text);
    int pusto = 0;
    for(int i = 0; i < 1000; i++)
    {
        if(isalpha(*(text+i)))
            pusto++;
    }
    char*** ukaz;
    int prov = split_sentences(text, &ukaz);
    if(prov == 2 || pusto == 0)
    {
        printf("Nothing to show");
        destroy(ukaz);
        free(text);
        return 0;
    }
    else if (prov == 3)
    {
        printf("Failed to allocate memory");
        free(text);
        return 8;
    }
    sort_sentences(ukaz);
    display(ukaz);
    free(text);
    destroy(ukaz);
    return 0;
}

int size(char** text)
{
    int size = 0;
    while(*(text+size)!= NULL)
    {
        size++;
    }
    return size;
}

void display(char ***words)
{
    if(words == NULL || *words == NULL)
        return;
    int i = 0, j = 0;
    while(*(words+i) != NULL)
    {
        j = 0;
        if(size(*(words+i)) == 0)
        {
            printf("Nothing to show\n");
            i++;
            continue;
        }
        while(*(*(words+i)+j) != NULL)
        {
            printf("%s ", *(*(words+i)+j));
            j++;
        }
        printf("\n");
        i++;
    }


}

int split_sentences(const char *text, char ****output)
{
    if(text == NULL || output == NULL)
    {
        return 1;
    }
    int i, length = (int)strlen(text), zdania = 0;
    for(i = 0; i < length; i++)
    {
        if(*(text+i) == '.')
        {
            zdania++;
        }
    }
    if(zdania == 0)
    {
        *output = NULL;
        return 2;
    }

    *output = calloc(zdania+1, sizeof(char**));
    if(*output == NULL)
        return 3;
    int count_words = 0;
    int current = 0, previous = 0;
    *(*output+zdania) = NULL;
    zdania = 0;
    for(i = 0; i < length; i++) {
        current = isalpha(*(text+i))?1:0;
        if(current == 1 && previous == 0)
        {
            count_words++;
        }
        if (*(text + i) == '.')
        {
            *(*output+zdania) = calloc(count_words == 0 ? 1:count_words+1, sizeof(char*));
            if(*(*output+zdania) == NULL)
            {
                for(int g = zdania-1; g >= 0; g--)
                {
                    free(*(*output+g));
                }
                free(*output);
                *output = NULL;
                return 3;
            }
            for(int x = 0; x < count_words+1; x++)
            {
                *(*(*output+zdania)+x) = NULL;
            }

            zdania++;
            count_words = 0;
        }
        previous = current;
    }

    int j = 0;
    current = 0, previous = 0;
    int word_begin;
    int licznik_slow;
    for(i = 0; i < zdania; i++)
    {
        licznik_slow = 0;
        do {
            current = isalpha(*(text + j)) ? 1 : 0;
            if (current == 1 && previous == 0)
            {
                word_begin = j;
            }
            if(current == 0 && previous == 1)
            {
                int word_lenght = j - word_begin;
                *(*(*output+i)+licznik_slow) = calloc(word_lenght+1, sizeof(char));
                if(*(*(*output+i)+licznik_slow) == NULL)
                {
                    destroy(*output);
                    *output = NULL;
                    return 3;
                }
                if(*(*(*output+i)+licznik_slow) != NULL)
                    strncpy(*(*(*output+i)+licznik_slow), text+word_begin, word_lenght);
                if(*(text + j) == '.')
                {
                    j++;
                    previous = current;
                    break;
                }
                licznik_slow++;
            }
            if(*(text + j) == '.' && licznik_slow == 0)
            {
                *(*(*output+i)+licznik_slow) = NULL;
                j++;
                previous = current;
                break;
            }
            if(*(text + j) == '.')
            {
                j++;
                previous = current;
                break;
            }
            j++;
            previous = current;
        }while(1);

    }
    return 0;
}

int sort_sentences(char ***output)
{
    if(output == NULL)
        return 1;
    int size_text = 0;
    while(*(output + size_text) != NULL)
    {size_text++;}
    for(int i = 0; i < size_text-1; i++)
    {
        for(int j = 0; j < size_text-i - 1; j++)
            if(size(*(output+j)) > size(*(output+j+1)))
            {
                char** temp = *(output+j);
                *(output+j) = *(output+j+1);
                *(output+j+1) = temp;
            }
    }
    for(int i = 0; i < size_text; i++)
    {
        if(size(*(output+i)) == 0)
        {
            continue;
        }
        for(int j = 0; j < size(*(output+i))-1; j++)
        {
            for(int g = 0; g < size(*(output+i))-1-j; g++)
            {
                if(strcmp(*(*(output+i)+g), *(*(output+i)+g+1)) > 0)
                {
                    char* temp = *(*(output+i)+g);
                    *(*(output+i)+g) = *(*(output+i)+g+1);
                    *(*(output+i)+g+1) = temp;
                }
            }
        }
    }
    return 0;
}
void destroy(char ***words)
{
    if(words == NULL || *words == NULL)
        return;
    int i = 0, j = 0;
    while(*(words+i) != NULL)
    {
        j = 0;
        while(*(*(words+i)+j) != NULL)
        {
            free(*(*(words+i)+j));
            j++;
        }
        free(*(words+i));
        i++;
    }
    free(words);
    words = NULL;

}



