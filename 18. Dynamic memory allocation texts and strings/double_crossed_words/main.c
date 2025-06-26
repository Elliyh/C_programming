#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tested_declarations.h"
#include "rdebug.h"
//#include "tested_declarations.h"
//#include "rdebug.h"

int create_leading_word_cross(const char *first, const char *second, char ***result);
int create_double_leading_word_cross(
        const char *first, const char *second, const char *third, const char *fourth,
         char ***result, char ***first_cross, char ***second_cross);

void destroy(char **words);

void display(char** words)
{
    if(words == NULL || *words == NULL)
    {
        return;
    }
    int i = 0;
    while(*(words+i) != NULL)
    {
        printf("%s\n", (*(words+i)));
        i++;
    }
}


int main() {
    char* first = calloc(11, sizeof(char));
    if(first == NULL){
        printf("Failed to allocate memory");
        return 8;
    }
    char* second = calloc(11, sizeof(char));
    if(second == NULL){
        printf("Failed to allocate memory");
        free(first);
        return 8;
    }
    char* third = calloc(11, sizeof(char));
    if(third == NULL){
        printf("Failed to allocate memory");
        free(first);
        free(second);
        return 8;
    }
    char* fourth = calloc(11, sizeof(char));
    if(fourth == NULL){
        printf("Failed to allocate memory");
        free(first);
        free(second);
        free(third);
        return 8;
    }
    int i;
    for(i = 0; i < 11; i++)
    {
        *(first+i) = '\0';
        *(second+i) = '\0';
        *(third+i) = '\0';
        *(fourth+i) = '\0';
    }
    printf("Enter words:");
    if(scanf("%10s %10s %10s %10s", first, second, third, fourth) != 4)
    {
        printf("Incorrect input");
        free(first);
        free(second);
        free(third);
        free(fourth);
        return 1;
    }
    char** result;
    char** first_cross;
    char** second_cross;
    int spraw = create_double_leading_word_cross(first, second, third, fourth, &result, &first_cross, &second_cross);
    if(spraw == 1)
    {
        printf("Incorrect input");
        free(first);
        free(second);
        free(third);
        free(fourth);
        return 1;
    }
    if(spraw == 2)
    {
        printf("Unable to make two crosses");
        free(first);
        free(second);
        free(third);
        free(fourth);
        return 0;
    }
    else if(spraw == 3)
    {
        printf("Failed to allocate memory");
        free(first);
        free(second);
        free(third);
        free(fourth);
        return 8;
    }
    display(first_cross);
    printf("\n");
    display(second_cross);
    printf("\n");
    display(result);
    destroy(first_cross);
    destroy(second_cross);
    destroy(result);
    free(first);
    free(second);
    free(third);
    free(fourth);
    return 0;
}



void destroy(char **words)
{
    if(words == NULL || *words == NULL)
    {
        return;
    }
    int i = 0;
    while(*(words+i) != NULL)
    {
        free(*(words+i));
        i++;
    }
    free(words);
}



int create_leading_word_cross(const char *first, const char *second, char ***result)
{
    if(first == NULL || second == NULL || result == NULL)
    {
        return -1;
    }

    int height, width;
    int flag = 0;
    if(strlen(first) == 0 || strlen(second) == 0)
        return -1;

    for(width = 0; width < (int)strlen(second); width++)
    {
        if(islower(*(second+width)) || !isalpha(*(second+width)))
            return -1;
    }

    for(height = 0; height < (int)strlen(first); height++)
    {
        if(islower(*(first + height)) || !isalpha(*(first + height)))
            return -1;
    }


    for(width = 0; width <= (int)strlen(second); width++)
    {
        for(height = 0; height <= (int)strlen(first); height++)
        {
            if(*(second+width) == *(first+height))
            {
                if(*(second+width) == '\0')
                {
                    *result = NULL;
                    return -2;
                }
                flag++;
                break;
            }
        }
        if(flag == 1)
            break;
    }
    int row = height;
    *result = calloc(strlen(first)+1, sizeof(char*));
    if(*result == NULL)
    {
        *result = NULL;
        return -3;
    }
    *(*result+strlen(first)) = NULL;
    int i;
    for(i = 0; i < (int)strlen(first); i++)
    {
        if(i == row)
        {
            *(*result+i) = calloc(strlen(second)+1, sizeof(char));
        }
        else
            *(*result+i) = calloc(width+2, sizeof(char));
        if(*(*result+i) == NULL)
        {
            int g = i-1;
            while(g>=0)
            {
                free(*((*result) + g));
                g--;
            }
            free(*result);
            *result = NULL;
            return -3;
        }
        if(i == row)
            *(*((*result)+i)+strlen(second)) = '\0';
        else
            *(*((*result)+i)+width+1) = '\0';
    }

    for(i = 0; i < (int)strlen(first); i++)
    {
        int g = 0;
        while(g < width)
        {
            *(*((*result)+i)+g) = ' ';
            g++;
        }
        *(*((*result)+i)+width) = *(first+i);
    }
    for (i = 0; i < (int)strlen(second); i++)
    {
        *(*((*result)+row)+i) = *(second+i);
    }
    return row;
}


int create_double_leading_word_cross(
        const char *first, const char *second, const char *third, const char *fourth,
        char ***result, char ***first_cross, char ***second_cross)
{
    if(first == NULL || second == NULL || third == NULL || fourth == NULL ||
    result == NULL || first_cross == NULL || second_cross == NULL)
        {
        return 1;
        }
    int spraw_1 = create_leading_word_cross(second, first, first_cross);
    if(spraw_1 == -1)
        return 1;
    else if(spraw_1 == -2)
    {*result = NULL;
        return 2;
    }

    else if(spraw_1 == -3)
        return 3;
    int spraw_2 = create_leading_word_cross(fourth, third, second_cross);
    if(spraw_2 == -1)
    {
        destroy(*first_cross);
        return 1;
    }
    else if(spraw_2 == -2)
    {
        destroy(*first_cross);
        *result = NULL;
        return 2;
    }
    else if(spraw_2 == -3)
    {
        destroy(*first_cross);
        *result = NULL;
        return 3;
    }
    int level = spraw_1 >= spraw_2 ? spraw_1 : spraw_2;
    int up_first_cross = spraw_1 <= level ? level-spraw_1 : 0;
    int up_second_cross = spraw_2 <= level ? level-spraw_2 : 0;

    int all_height = up_first_cross+strlen(second) > up_second_cross+strlen(fourth) ? up_first_cross+(int)strlen(second) : up_second_cross+(int)strlen(fourth);

    int down_first_cross = all_height - (up_first_cross+(int)strlen(second));
    int down_second_cross = all_height - (up_second_cross+(int)strlen(fourth));

    int space_first_cross, space_second_cross;
    for(int i = 0; i < (int)strlen(second); i++)
    {
        if(i != spraw_1)
        {
            space_first_cross = (int)strlen(*(*first_cross+i))-1;
            break;
        }

    }
    for(int i = 0; i < (int)strlen(fourth); i++)
    {
        if(i != spraw_2)
        {
            space_second_cross = (int)strlen(*(*second_cross+i))-1;
            break;
        }

    }

    *result = calloc(all_height+1, sizeof(char*));
    if(*result == NULL) {
        destroy(*first_cross);
        destroy(*second_cross);
        return 3;
    }
    int i, size;
    for(i = 0; i < all_height; i++)
    {
        if(i != level && i < level)
        {
            size = (int)strlen(first)+3+2+space_second_cross;
            *(*result+i) = calloc(up_second_cross > i  ? space_first_cross+2 : size, sizeof(char));
        }
        else if(i != level && i > level)
        {
            size = (int)strlen(first)+3+2+space_second_cross;
            *(*result+i) = calloc(all_height - 1 - i < down_second_cross ? space_first_cross+2 : size, sizeof(char));
        }
        else
        {
            size = strlen(first)+3+strlen(third)+1;
            *(*result+i) = calloc(size, sizeof(char));
        }

        if(*(*result+i) == NULL)
        {
            int g = i-1;
            while(g>=0)
            {
                free(*((*result) + g));
                g--;
            }
            free(*result);
            *result = NULL;
            destroy(*first_cross);
            destroy(*second_cross);
            return 3;
        }

    }
    *(*result+all_height) = NULL;

    int index_first_cross = 0, index_second_cross = 0;

    for(i = 0; i < all_height; i++)
    {
        if(i != level && i < level)
        {
            if(up_second_cross > i)
            {

                strcpy(*(*result+i), *(*first_cross+index_first_cross));
                index_first_cross++;
                *(*(*result + i)+strlen(*(*first_cross+i))) = '\0';
            }
            else if(up_first_cross > i)
            {
                int j;
                for (j = 0; j < (int)strlen(first)+3+space_second_cross; j++)
                {
                    *(*(*result+i)+j) = ' ';
                }
                *(*(*result+i)+j) = *(fourth+index_second_cross);
                index_second_cross++;
                *(*(*result+i)+j+1) = '\0';
            }
            else
            {
                strcpy(*(*result+i), *(*first_cross+index_first_cross));
                for(int g = 0; g < (int)strlen(*(*first_cross+spraw_1))- (int)strlen(*(*first_cross+index_first_cross)); g++)
                {
                    strcat(*(*result+i), " ");
                }
                strcat(*(*result+i), "   ");
                strcat(*(*result+i), *(*second_cross+index_second_cross));
                index_first_cross++;
                index_second_cross++;
            }
        }
        else if(i != level && i > level)
        {
            if(i +1 > all_height - down_first_cross)
            {
                int j;
                for (j = 0; j < (int)strlen(first)+3+space_second_cross; j++)
                {
                    *(*(*result+i)+j) = ' ';
                }
                *(*(*result+i)+j) = *(fourth+index_second_cross);
                index_second_cross++;
                *(*(*result+i)+j+1) = '\0';
            }
            else if (i +1 > all_height - down_second_cross)
            {
                strcpy(*(*result+i), *(*first_cross+index_first_cross));
                *(*(*result + i)+strlen(*(*first_cross+index_first_cross))) = '\0'; //gfdgdf
                index_first_cross++;

            }
            else
            {
                strcpy(*(*result+i), *(*first_cross+index_first_cross));
                for(int g = 0; g < (int)strlen(*(*first_cross+spraw_1))- (int)strlen(*(*first_cross+index_first_cross)); g++)
                {
                    strcat(*(*result+i), " ");
                }
                strcat(*(*result+i), "   ");
                strcat(*(*result+i), *(*second_cross+index_second_cross));
                index_first_cross++;
                index_second_cross++;
            }
        }
        else
        {
            strcpy(*(*result+i), *(*first_cross+index_first_cross));
            for(int g = 0; g < (int)strlen(*(*first_cross+spraw_1))- (int)strlen(*(*first_cross+index_first_cross)); g++)
            {
                strcat(*(*result+i), " ");
            }
            strcat(*(*result+i), "   ");
            strcat(*(*result+i), *(*second_cross+index_second_cross));
            index_first_cross++;
            index_second_cross++;
        }
    }
    return 0;
}

