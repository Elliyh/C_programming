#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "tested_declarations.h"
#include "rdebug.h"


union bit_set_letter {
    uint8_t letter_byte;
};

union bit_set_piksel
{
    uint8_t piksel_byte;
};

int encode(const char *input, char *txt, const char *output)
{
    if(input == NULL || txt == NULL || output == NULL)
    {
        return 1;
    }
    FILE* file_input = fopen(input, "r");
    if (file_input == NULL)
        return 2;
    FILE* file_output = fopen(output, "w");
    if (file_output == NULL)
    {
        fclose(file_input);
        return 4;
    }
    fseek(file_input, 0, SEEK_END);
    int len_input = ftell(file_input);
    //int len_txt = strlen(txt);
    fseek(file_input, 0, SEEK_SET);
    if(strlen(txt) > (unsigned int)len_input/8)
    {
        fclose(file_input);
        fclose(file_output);
        return 3;
    }
    int i = 0;
    union bit_set_letter letter;
    union bit_set_piksel new_piksel;
    char delim;//byte = (byte<<1)|(number&0x01);
    while(!(feof(file_input)))
    {

        if(letter.letter_byte != '0' && i % 8 == 0)
        {
            if(*(txt+(i/8)) == '\0')
                letter.letter_byte = '0';
            else if (letter.letter_byte != '0')
                letter.letter_byte = *(txt+(i/8));
        }
        if(!fscanf(file_input, "%hhu", &new_piksel.piksel_byte))
        {
            fclose(file_input);
            fclose(file_output);
            return 3;
        }
        if (letter.letter_byte == '0')
        {
            if(new_piksel.piksel_byte%2 == 1)
                new_piksel.piksel_byte = new_piksel.piksel_byte - 1;
        }
        else {
            uint8_t mask = new_piksel.piksel_byte & 1;// jest li najm 1 ili net
            uint8_t sprawd = letter.letter_byte & (uint8_t)(pow(2, 7 - i % 8));
            if (sprawd) {
                if (!mask)
                    new_piksel.piksel_byte = new_piksel.piksel_byte | 1; // zmieni w pikselu 1 na 0(w mask)
            } else {
                if (mask)
                    new_piksel.piksel_byte = new_piksel.piksel_byte & ~(1); // zmieni w pikselu 0 na 1(w mask)
            }
        }
        delim = getc(file_input);
        if(delim == ' ')
            fprintf(file_output, "%d%c", new_piksel.piksel_byte, delim);
        delim = getc(file_input);
        if(delim == '\n')
            fprintf(file_output, "%c", delim);
        else
            ungetc(delim, file_input);
        i++;
    }
    fclose(file_input);
    fclose(file_output);

    return 0;
}

int decode(const char * filename, char *txt, int size)
{
    if(filename == NULL || txt == NULL || size <= 0)
        return 1;
    FILE *f = fopen(filename, "r");
    if (f == NULL)
    {
        return 2;
    }
    int i = 0, j = 0;
    uint8_t number;
    char byte = 0;
    while(!feof(f) && i < size-1)
    {
        if(fscanf(f, "%hhu", &number) != 1)
        {
            fclose(f);
            return 3;
        }
        byte = (byte<<1)|(number&0x01);
        j++;
        if(j == 8)
        {
            if (byte == '\0')
            {
                *(txt+i) = '\0';
                break;
            }
            j = 0;
            if((txt+i)!= NULL)
                *(txt+i) = byte;
            i++;
            byte = 0;
        }
    }
    *(txt+i) = '\0';
    fclose(f);
    return 0;

}






int main() {
    printf("Podaj litere E/e dla encodu lub D/d dla decodu:");
    char my_text[1001] = {'\0'}, output_text[1001] = {'\0'},file_input[30] = {'\0'}, file_output[30] = {'\0'}, mode;
    scanf("%c", &mode);
    while(getchar() != '\n'){}
    if(mode != 'd' && mode != 'D' && mode != 'E' && mode != 'e')
    {
        printf("Incorrect input data");
        return 1;
    }
    mode = toupper(mode);
    int err_code;
    switch (mode)
    {
        case 'E':
            printf("Podaj swoj tekst:");
            scanf("%1000[^\n]", my_text);
            while(getchar() != '\n'){}
            printf("Podaj nazwe pliku wejsciwego: ");
            scanf("%29[^\n]", file_input);
            while(getchar() != '\n'){}
            printf("Podaj nazwe pliku wyjsciwego: ");
            scanf("%29[^\n]", file_output);
            while(getchar() != '\n'){}
            err_code = encode(file_input, my_text, file_output);
            if (err_code == 0) {
                printf("File saved");
                return 0;
            } else if (err_code == 2) {
                printf("Couldn't open file");
                return 4;
            } else if (err_code == 4) {
                printf("couldn't create file");
                return 5;
            } else if (err_code == 3) {
                printf("File corrupted");
                return 6;
            }
            break;
        case 'D':
            printf("Podaj nazwe pliku wejsciwego: ");
            scanf("%29[^\n]", file_input);
            while(getchar() != '\n'){}
            err_code = decode(file_input, output_text, 1000);
            if (err_code == 2) {
                printf("couldn't open file");
                return 4;
            }
            else if (err_code == 3) {
                printf("File corrupted");
                return 6;
            }
            printf("%s", output_text);
            break;
    }
    return 0;
}




