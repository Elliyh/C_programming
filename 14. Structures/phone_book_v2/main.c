#include <stdio.h>
#include <string.h>
#include "tested_declarations.h"
#include "rdebug.h"
//#include "tested_declarations.h"
//#include "rdebug.h"


struct entry_t {
    char name[20];
    char last_name[40];
    int number;
};

void display(const struct entry_t* p) {
    if (p == NULL)
        return;
    printf("Name: %s\nLast name: %s\nPhone number: %d", p->name, p->last_name, p->number);
}


const struct entry_t* find_by_last_name(const struct entry_t* p, int size, const char *last_name)
{
    if(p == NULL || size <= 0 || last_name == NULL)
        return NULL;

    int i;
    for(i = 0; i < size; i++)
    {
        if(strcmp(last_name, (p+i)->last_name) == 0)
            return p+i;
    }
    return NULL;
}


int load_phonebook_t(const char *filename, struct entry_t* p, int size)
{
    if(filename == NULL || p == NULL || size <= 0)
    {
        return -1;
    }

    FILE *fp = fopen(filename, "r");
    if(fp == NULL)
    {
        return -2;
    }
    int i = 0;
    int count_record = 0;
    while(!feof(fp) && i < size)
    {
        char text[101] = {'\0'};
        int count_stick = 0;
        fscanf(fp, "%100[^\n]", text);
        getc(fp);
        for(int j = 0; j < (int)strlen(text); j++)
        {
            if(*(text+j) == '|')
                count_stick++;
        }
        if (count_stick != 2)
            continue;
        else
        {
            fseek(fp, -(strlen(text)+1), SEEK_CUR);
        }
        if(fscanf(fp, "%19s | %39[^|]| %d", (p+i)->name, (p+i)->last_name, &(p+i)->number) == 3)
        {
            int len = strlen((p+i)->last_name);
            *((p+i)->last_name+len-1) = '\0';
            count_record++;
            getc(fp);
        }
        else
        {
            memset((p+i) -> name, '\0', sizeof((p+i) -> name));
            memset((p+i) -> last_name, '\0', sizeof((p+i) -> last_name));
            i--;
        }
        i++;
    }
    fclose(fp);
    return count_record;
}

int remove_entry_by_last_name(struct entry_t* p, int size, const char* last_name)
{
    if(p == NULL || size <= 0 || last_name == NULL)
    {
        return size;
    }
    int i;
    for(i = 0; i < size; i++)
    {
        if(strcmp(last_name, (p+i)->last_name) == 0)
        {
            int j;
            for(j = i; j < size; j++)
            {
                strcpy((p+j)->last_name, (p+j+1)->last_name);
                strcpy((p+j)->name, (p+j+1)->name);
                (p+j)->number = (p+j+1)->number;
            }
            return size-1;
        }
    }
    return size;
}


int save_phonebook_t(const char *filename, const struct entry_t* p, int size)
{
    if(filename == NULL || p == NULL || size <= 0)
        return -1;

    FILE *fp = fopen(filename, "w");
    if(fp == NULL)
    {
        return -2;
    }

    int i;
    for(i = 0; i<size; i++)
    {
        fprintf(fp, "%s | %s | %d", (p+i)->name, (p+i) -> last_name, (p+i)->number);
        if(i != size - 1)
            fprintf(fp, "\n");
    }
    fclose(fp);
    return i;
}

int main() {
    struct entry_t my_array[10];
    char filename [101] = {'\0'};
    char lastname [40] = {'\0'};
    printf("Enter file name: ");
    scanf("%100[^\n]", filename);
    while(getchar()!='\n'){}
    int spraw = load_phonebook_t(filename, my_array, 10);
    if (spraw == -2 || spraw == -1)
    {
        printf("Couldn't open file");
        return 4;
    }
    else if (spraw == 0)
    {
        printf("File corrupted");
        return 6;
    }
    printf("Enter last name: ");
    scanf("%39[^\n]", lastname);
    char new_filename [111] = {'\0'};
    snprintf(new_filename, sizeof(new_filename)+10, "expected_%s", filename);
    int new_size = remove_entry_by_last_name(my_array, spraw, lastname);
    if(new_size == spraw)
    {
        printf("Couldn't find name");
        return 0;
    }
    else
    {
        printf("Entry removed\n");
        int spraw_2 = save_phonebook_t(filename, my_array, new_size);
        if(spraw_2 == -2)
        {
            printf("Couldn't create file");
            return 6;
        }
        else
        {
            printf("File saved");
        }
    }
    return 0;
}
