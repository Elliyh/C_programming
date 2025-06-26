#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "format_type.h"
#include "tested_declarations.h"
#include "rdebug.h"
//#include "tested_declarations.h"
//#include "rdebug.h"



struct statistic_t
{
    int min;
    int max;
    float avg;
    float standard_deviation;
    int range;
};



int statistics(int **ptr, struct statistic_t **stats);
void display(int **ptr);
int save(const char *filename, int **ptr, enum save_format_t format);


int main() {
    int A[] = {10, 20, 30, 40, 50, 60, 70, -1};
    int B[] = {100, 200, 300, 400, 500, 600, 700, 800, -1};
    int C[] = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, -1};
    int* D[] = {A, B, C, NULL};
    display(D);
    char* filename_1 = malloc(40*sizeof(char));
    if(filename_1 == NULL)
    {
        printf("failed to allocate memory");
        return 8;
    }
    printf("Podaj nazwe pliku:");
    int i;
    for(i = 0; i < 40; i++)
    {
        *(filename_1+i) = '\0';
    }
    scanf("%39s", filename_1);

    char* filename_2 = malloc(40*sizeof(char));
    if(filename_2 == NULL)
    {
        printf("failed to allocate memory"); //northhadtriangleteamtopshoediscussconne
        free(filename_1);
        return 8;
    }


    strcpy(filename_2, filename_1);
    filename_1 = realloc(filename_1, 44);
    filename_2 = realloc(filename_2, 44);
    strcat(filename_1, ".txt\0");
    strcat(filename_2, ".bin\0");
    int spraw = save(filename_1, D, fmt_text);
    if(spraw == 2)
    {
        printf("Couldn't create file\n");
    }
    else if(spraw == 0)
    {
        printf("File saved\n");
    }
    spraw = save(filename_2, D, fmt_binary);
    free(filename_1);
    free(filename_2);
    if(spraw == 2)
    {
        printf("Couldn't create file\n");
    }
    else if(spraw == 0)
    {
        printf("File saved\n");
    }



    struct statistic_t* stats;
    int prov = statistics(D, &stats);
    if (prov == 2)
    {
        printf("failed to allocate memory");
        return 8;
    }
    printf("%d\n%d\n%d\n%.2f\n%.2f\n", stats->min, stats->max, stats->range, stats->avg, stats->standard_deviation);
    free(stats);
    return 0;
}


int save(const char *filename, int **ptr, enum save_format_t format)
{
    if(filename == NULL || (format != fmt_binary && format != fmt_text) || ptr == NULL)
    {
        return 1;
    }
    FILE *f;
    int i, j;
    switch (format){
        case fmt_text:
            f = fopen(filename, "w");
            if(f==NULL)
                return 2;
            i = 0, j = 0;
            while(*(ptr+i) != NULL)
            {
                while(*(*(ptr+i)+j) != -1)
                {
                    fprintf(f, "%d ", *(*(ptr+i)+j));
                    j++;
                }
                if(*(*(ptr+i)+j) == -1)
                {
                    fprintf(f, "%d\n", *(*(ptr+i)+j));
                    j = 0;
                    i++;
                }
            }
            fclose(f);
            break;
        case fmt_binary:
            f = fopen(filename, "wb");
            if(f==NULL)
                return 2;
            i = 0, j = 0;
            while(*(ptr+i) != NULL)
            {
                while(*(*(ptr+i)+j) != -1)
                {
                    fwrite((*(ptr+i)+j), sizeof(int), 1, f);
                    j++;
                }
                if(*(*(ptr+i)+j) == -1)
                {
                    fwrite((*(ptr+i)+j), sizeof(int), 1, f);
                    j = 0;
                    i++;
                }
            }
            fclose(f);
            break;
    }
    return 0;
}


void display(int **ptr)
{
    if(ptr == NULL || *ptr == NULL)
        return;
    int i = 0;

    while(*(ptr+i) != NULL)
    {
        int j = 0;
        while((*(ptr+i)+j) != NULL && *(*(ptr+i)+j) != -1)
        {
            printf("%d ", *(*(ptr+i)+j));
            j++;
        }
        printf("\n");
        i++;
    }
}



int statistics(int **ptr, struct statistic_t **stats)
{
    if(ptr == NULL || stats == NULL){
        return 1;
    }
    *stats = malloc(sizeof(struct statistic_t));
    if(*stats == NULL)
        return 2;
    int i = 0, j = 0;
    int sum= 0;
    float sum_deviation = 0;
    int count = 0;
    while(*(ptr+i) != NULL)
    {
        if(*(*(ptr+i)+j) == -1)
        {
            j = 0;
            i++;
            continue;
        }
        if(j == 0 && i == 0)
        {

            (*stats) ->min = *(*(ptr+i)+j);
            (*stats)->max = *(*(ptr+i)+j);
        }
        if(*(*(ptr+i)+j) < (*stats)->min)
            (*stats)->min = *(*(ptr+i)+j);
        if(*(*(ptr+i)+j) > (*stats)->max)
            (*stats)->max = *(*(ptr+i)+j);
        sum_deviation += pow((float)*(*(ptr+i)+j), 2);
        sum += *(*(ptr+i)+j);
        count++;
        j++;
    }
    if(count == 0)
    {
        free(*stats);
        return 3;

    }

    (*stats)->avg = (float) sum / (float)count;
    (*stats)->standard_deviation = sqrt((float)(sum_deviation /  (float)count) - ((*stats) -> avg * (*stats) -> avg));
    (*stats)->range = (*stats)->max - (*stats)->min;
    return 0;
}








