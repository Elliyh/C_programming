#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tested_declarations.h"
#include "rdebug.h"
//#include "tested_declarations.h"
//#include "rdebug.h"


int load_maze(const char *filename, char ***labirynth);
int solve_maze(char **maze, int x, int y);
void free_maze(char **maze);
void display(char** maze);


int main() {
    char* filename = calloc(31, sizeof(char));
    if(filename == NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    int i;
    for(i = 0; i < 31; i++)
    {
        *(filename+i) = '\0';
    }
    printf("Enter filename:");
    scanf("%30[^\n]", filename);
    char** labirinth;
    int spraw = load_maze(filename, &labirinth);
    free(filename);
    if(spraw == 2)
    {
        printf("Couldn't open file");
        return 4;
    }
    if(spraw == 3)
    {
        printf("File corrupted");
        free_maze(labirinth);
        return 6;
    }
    if(spraw == 4)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    int x = 0, y = 0;
    while(*(*(labirinth+y)+x) != 'a')
    {
        if(*(*(labirinth+y)+x) == '\0')
        {
            y++;
            x = 0;
        }

        x++;
    }
    spraw =  solve_maze(labirinth, x, y);
    if(spraw == -1)
    {
        printf("File corrupted");
        free_maze(labirinth);
        return 6;
    }
    if(spraw == 0)
    {
        printf("Couldn't find path");
        free_maze(labirinth);
        return 0;
    }
    if(spraw == 1)
    {
        display(labirinth);
        free_maze(labirinth);
    }
    return 0;

}

void free_maze(char **maze)
{
    if(maze == NULL || *maze == NULL)
    {
        return;
    }
    int i = 0;
    while(*(maze+i) != NULL)
    {
        free(*(maze+i));
        i++;
    }
    free(maze);
}

void display(char **maze)
{
    if(maze == NULL || *maze == NULL)
    {
        return;
    }
    int i = 0;
    while(*(maze+i) != NULL)
    {
        printf("%s\n", *(maze+i));
        i++;
    }
}

int load_maze(const char *filename, char ***labirynth)
{
    if(filename == NULL || labirynth == NULL )
    {
        return 1;
    }
    /*char* new_filename = calloc(strlen(filename)+5, sizeof(char));
    if(new_filename == NULL)
        return 4;
    strcpy(new_filename, filename);
    strcat(new_filename, ".txt\0");*/

    FILE *f = fopen(filename, "r");
    if(f == NULL)
    {
        //free(new_filename);
        return 2;
    }
    //free(new_filename);
    int row = 0, col = 0, i = 0, j = 0;
    char sym = '#';
    while(1)
    {
        fscanf(f, "%c", &sym);
        if(sym == '\n' || feof(f))
            break;
        col++;
    }
    if(col <= 2)
    {
        fclose(f);
        return 3;
    }

    fseek(f, 0, SEEK_SET);
    while(1)
    {
        if(feof(f))
        {
            if (i-1 != col)
            {
                fclose(f);
                return 3;
            }
            row++;
            break;
        }
        fscanf(f, "%c", &sym);
        if(sym == '\n')
        {

            i = 0;
            row++;
            continue;
        }
        i++;
    }
    if(row<= 2)
    {
        fclose(f);
        return 3;
    }
    *labirynth = calloc(row+1, sizeof(char*));
    if(*labirynth == NULL)
    {
        fclose(f);
        return 4;
    }
    for(i = 0; i < row; i++)
    {
        *((*labirynth) + i) = calloc(col+1, sizeof(char));
        if(*((*labirynth) + i) == NULL)
        {
            int g = i-1;
            while(g>=0)
            {
                free(*((*labirynth) + g));
                g--;
            }
            free(*labirynth);
            fclose(f);
            return 4;
        }

    }
    *((*labirynth) + row) = NULL;
    fseek(f, 0, SEEK_SET);
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col+1; j++)
        {
            fscanf(f, "%c", &sym);
            if(sym == '\n' || feof(f))
            {
                *(*((*labirynth)+i)+j) = '\0';
                break;
            }
            *(*((*labirynth)+i)+j) = sym;
        }

    }
    //display(*labirynth);
    fclose(f);
    return 0;
}


int solve_maze(char **maze, int x, int y)
{
    if(maze == NULL || *maze == NULL || x <= 0 || y <= 0)
        return -1;
    int i = 0, j = 0;
    while(*(*(maze+i)+j) != '\0')
    {
        j++;
    }
    int col = j;
    while(*(maze+i) != NULL)
    {
        i++;
    }
    int row = i;
    int count_a = 0, count_b = 0;
    if(row <= 2 || col <= 2 || x >= col || y >= row)
        return -1;
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            if(*(*(maze+i)+j) != 'a' && *(*(maze+i)+j) != 'b' && *(*(maze+i)+j) != '#' && *(*(maze+i)+j) != ' ' && *(*(maze+i)+j) != '*')
            {
                return -1;
            }
            if(*(*(maze+i)+j) == 'a')
                count_a++;
            if(*(*(maze+i)+j) == 'b')
                count_b++;
        }
    }
    if (count_a != 1 || count_b != 1)
        return -1;
    for(i = 0; i < row; i++)
    {
        if(i == 0 || i == row-1)
        {
            for(j = 0; j < col; j++)
            {
                if(*(*(maze+i)+j) != '#')
                    return -1;
            }
        }
        if(*(*(maze+i)+0) != '#' && *(*(maze+i)+col-1) != '#')
            return -1;
    }
    if(*(*(maze+y)+x) == '#')
        return -1;
    if(*(*(maze+y)+x) == 'b')
        return 1;
    /*if((*(*(maze+y)+x+1) != '#' && *(*(maze+y)+x+1) != '*' && solve_maze(maze, y, x+1)) || (*(*(maze+y+1)+x) != '#' && *(*(maze+y+1)+x ) != '*'&& solve_maze(maze, y+1, x))
    || (*(*(maze+y)+x-1) != '#' && *(*(maze+y)+x-1) != '*'&& solve_maze(maze, y, x-1)) || (*(*(maze+y-1)+x) != '#' && *(*(maze+y)+x-1)
    != '*') && solve_maze(maze, y-1, x))*/
    if(*(*(maze+y)+x) != 'a' && *(*(maze+y)+x) != '#')
        *(*(maze+y)+x) = '*';
    if((*(*(maze+y)+x+1) != '#' && *(*(maze+y)+x+1) != '*' && *(*(maze+y)+x+1) != 'a' && solve_maze(maze, x+1, y))
       || (*(*(maze+y+1)+x) != '#' && *(*(maze+y+1)+x) != '*' && *(*(maze+y+1)+x) != 'a' && solve_maze(maze, x, y+1)) ||
       (*(*(maze+y-1)+x) != '#' && *(*(maze+y-1)+x) != '*' && *(*(maze+y-1)+x) != 'a' && solve_maze(maze, x, y-1))
       || (*(*(maze+y)+x-1) != '#' && *(*(maze+y)+x-1) != '*' && *(*(maze+y)+x-1) != 'a' && solve_maze(maze, x-1, y)))
    {
        return 1;
    }
    *(*(maze+y)+x) = ' ';
    return 0;
}

