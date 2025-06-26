#include <stdio.h>
#include <string.h>
#include "tested_declarations.h"
#include "rdebug.h"


struct message_t
{
    char a;
    double b;
    int c;
};

int load_data(struct message_t *cp, int size, const char *filename)
{
    if(cp == NULL || size <= 0 || filename == NULL)
    {
        return -1;
    }

    FILE *fp = fopen(filename, "rb");
    if(fp == NULL)
    {
        return -2;
    }

    unsigned int n;
    if(fread(&n, sizeof(unsigned int), 1, fp) != 1)
    {
        fclose(fp);
        return -3;
    }
    if(n%24 != 0)
    {
        fclose(fp);
        return -3;
    }

    int i;
    for(i = 0; i < size && i < (int)n/24; i++)
    {
        if(fread(cp+i, sizeof(struct message_t), 1, fp) != 1)
        {
            fclose(fp);
            return -3;
        }

    }
    fclose(fp);
    return i;

}


int decode_message(const struct message_t *cp, int size, char *msg, int text_size)
{
    if(cp == NULL || size <=0 || msg == NULL || text_size <= 0)
    {
        return 1;
    }
    int i;
    int my_text_pointer = 0;
    for (i = 0; i < text_size; i++)
    {
        *(msg+i) = '\0';
    }
    for(i = 0; i < size; i++)
    {
        char* ukaz = (char *)(cp + i) + 1;;
        memcpy(msg+my_text_pointer, ukaz, 7);
        my_text_pointer += 7;
        ukaz = (char *)(cp + i) + 20;
        memcpy(msg+my_text_pointer, ukaz, 4);
        my_text_pointer += 4;
    }
    *(msg + text_size - 1) = '\0';
    return 0;

}

int main() {
    char filename [31] = {'\0'};
    struct message_t my_struct [150];
    char text [1300] = {'\0'};
    printf("Enter file name: ");
    scanf("%30[^\n]", filename);
    int count_struct = load_data(my_struct, 100, filename);

    if (count_struct == -2)
    {
        printf("Couldn't open file");
        return 4;
    }
    if (count_struct == -3)
    {
        printf("File corrupted");
        return 6;
    }
    else
    {
        decode_message(my_struct, count_struct, text, 1300);
        printf("%s", text);
    }
    return 0;
}



