#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "format_type.h"
#include "tested_declarations.h"
#include "rdebug.h"



struct statistic_t
{
    int min;
    int max;
    float avg;
    float standard_deviation;
    int range;
};



int load(const char *filename, int ***ptr, enum save_format_t format);
int statistics_row(int **ptr, struct statistic_t **stats);
void destroy(int ***ptr);
void display(int **ptr);


int main() {
    char* filename = malloc(40*sizeof(char));
    if(filename == NULL)
    {
        printf("failed to allocate memory");
        return 8;
    }
    printf("Podaj nazwe pliku:");
    int i;
    for(i = 0; i < 40; i++)
    {
        *(filename+i) = '\0';
    }
    for(i = 0; i < 39; i++)
    {
        char sym;
        scanf("%c", &sym);
        if(sym == '\n')
            break;
        *(filename+i) = sym;
    }
    enum save_format_t type;
    int len = strlen(filename);
    if(*(filename+len-1) == 't' && *(filename+len-2) == 'x' && *(filename+len-3) == 't' && *(filename+len-4) == '.')
        type = fmt_text;
    else if (*(filename+len-1) == 'n' && *(filename+len-2) == 'i' && *(filename+len-3) == 'b' && *(filename+len-4) == '.')
        type = fmt_binary;
    else
    {
        free(filename);
        printf("Unsupported file format");
        return 7;
    }
    int ** ukaz;
    int spraw = load(filename, &ukaz, type);
    free(filename);
    if(spraw == 2)
    {
        printf("Couldn't open file");
        return 4;
    }
    else if(spraw == 3)
    {
        printf("File corrupted");
        return 6;
    }
    else if(spraw == 4)
    {
        printf("failed to allocate memory");
        return 8;
    }
    struct statistic_t* stats;
    int prov = statistics_row(ukaz, &stats);
    if (prov == -2)
    {
        printf("failed to allocate memory");
        return 8;
    }
    int j;
    for(j = 0; j < prov; j++)
    {
        printf("%d %d %d %.2f %.2f\n", (stats+j)->min, (stats+j)->max, (stats+j)->range, (stats+j)->avg, (stats+j)->standard_deviation);
    }
    free(stats);
    destroy(&ukaz);
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



int statistics_row(int **ptr, struct statistic_t **stats)
{
    if(ptr == NULL || stats == NULL){
        return -1;
    }
    int count_row = 0;
    while(1)
    {
        if(*(ptr+count_row) == NULL)
            break;
        count_row++;
    }
    struct statistic_t* ukaz = calloc(count_row, sizeof(struct statistic_t));
    if(ukaz == NULL){
        return -2;
    }
    int i, j;
    for(i = 0; i < count_row; i++)
    {
        j = 0;
        int sum= 0;
        float sum_deviation = 0;
        while(1)
        {
            if(*(*(ptr+i)+j) == -1)
            {
                if(j == 0)
                {
                    (ukaz+i)->min = -1;
                    (ukaz+i)->max = -1;
                    (ukaz+i)->standard_deviation = -1;
                    (ukaz+i)->avg = -1;
                    (ukaz+i)->range = -1;
                }
                break;
            }
            if(j == 0)
            {
                (ukaz+i)->min = *(*(ptr+i)+j);
                (ukaz+i)->max = *(*(ptr+i)+j);
            }
            if(*(*(ptr+i)+j) < (ukaz+i)->min)
                (ukaz+i)->min = *(*(ptr+i)+j);
            if(*(*(ptr+i)+j) > (ukaz+i)->max)
                (ukaz+i)->max = *(*(ptr+i)+j);
            sum_deviation += pow((float)*(*(ptr+i)+j), 2);
            sum += *(*(ptr+i)+j);
            j++;
        }
        if(j != 0){
            (ukaz + i)->avg = (float) sum / (float)j;
            (ukaz + i)->standard_deviation = sqrt((float)(sum_deviation /  (float)j) - ((ukaz + i) -> avg * (ukaz + i) -> avg));
            (ukaz+i)->range = (ukaz+i)->max - (ukaz+i)->min;
        }
    }
    *stats = ukaz;
    return count_row;
}

void destroy(int ***ptr)
{
    if(ptr == NULL || *ptr == NULL)
    {
        return;
    }
    int i = 0;
    while(*((*ptr)+i) != NULL)
    {
        free(*((*ptr)+i));
        i++;
    }
    free(*ptr);
    *ptr = NULL;
}





int load(const char *filename, int ***ptr, enum save_format_t format){
    if(filename == NULL || (format != fmt_binary && format != fmt_text) || ptr == NULL)
    {
        return 1;
    }
    FILE *f;
    int row = 0, number, col = 0, i;
    switch (format){
        case fmt_text:
            f = fopen(filename, "r");
            if(f==NULL)
                return 2;
            row = 0;
            while(!feof(f)){
                if(!fscanf(f, "%d", &number))
                {
                    fclose(f);
                    return 3;
                }
                if(feof(f))
                    break;
                if(number == -1)
                    row++;

            }
            fseek(f, 0, SEEK_SET);
            if(row <= 0)
            {
                fclose(f);
                return 3;
            }
            int** rows = malloc((row+1) * sizeof(int*));
            if(rows == NULL)
            {
                fclose(f);
                return 4;
            }
            for(i = 0; i < row; i++)
            {
                col = 0;

                while(1) {
                    if (!fscanf(f, "%d", &number)) {
                        destroy(&rows);
                        fclose(f);
                        return 3;
                    }
                    else {
                        col++;
                        if(number == -1)
                        {
                            *(rows+i) = malloc(col*sizeof(int));
                            if (*(rows+i) == NULL)
                            {
                                destroy(&rows);
                                fclose(f);
                                return 4;
                            }
                            break;
                        }
                    }
                }
            }
            fseek(f, 0, SEEK_SET);
            for(i = 0; i < row; i++)
            {
                int j = 0;
                while(!feof(f)) {
                    if (!fscanf(f, "%d", &number)) {
                        destroy(&rows);
                        fclose(f);
                        return 3;
                    }
                    else {
                        if(number == -1)
                        {
                            *(*(rows+i)+j) = number;
                            break;
                        }
                        *(*(rows+i)+j) = number;
                        j++;
                    }
                }

            }
            *(rows+row) = NULL;
            *ptr =  rows;
            fclose(f);
            break;
        case fmt_binary:
            f = fopen(filename, "rb");
            if(f==NULL)
                return 2;
            row = 0;
            while(fread(&number, sizeof(int), 1, f) == 1){
                if(number == -1)
                    row++;
            }
            fseek(f, 0, SEEK_SET);
            if(row <= 0)
            {
                fclose(f);
                return 3;
            }

            rows = malloc((row+1) * sizeof(int*));
            if(rows == NULL)
            {
                fclose(f);
                return 4;
            }

            for(i = 0; i < row; i++)
            {
                col = 0;

                while(1) {
                    if (!fread(&number, sizeof(int), 1, f)) {
                        destroy(&rows);
                        fclose(f);
                        return 3;
                    }
                    else {
                        col++;
                        if(number == -1)
                        {
                            *(rows+i) = malloc(col*sizeof(int));
                            if (*(rows+i) == NULL)
                            {
                                destroy(&rows);
                                fclose(f);
                                return 4;
                            }
                            break;
                        }
                    }
                }
            }
            fseek(f, 0, SEEK_SET);
            for(i = 0; i < row; i++)
            {
                int j = 0;
                while(!feof(f)) {
                    if (!fread(&number, sizeof(int), 1, f)) {
                        destroy(&rows);
                        fclose(f);
                        return 3;
                    }
                    else {
                        if(number == -1)
                        {
                            *(*(rows+i)+j) = number;
                            break;
                        }
                        *(*(rows+i)+j) = number;
                        j++;
                    }
                }

            }
            *(rows+row) = NULL;
            *ptr =  rows;
            fclose(f);
            break;
    }
    return 0;
}


