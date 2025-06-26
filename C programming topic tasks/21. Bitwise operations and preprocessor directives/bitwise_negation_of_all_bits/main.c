#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "tested_declarations.h"
#include "rdebug.h"
//#include "tested_declarations.h"
//#include "rdebug.h"

void show(const void* ptr, size_t count) {
    const uint8_t* bytes = (const uint8_t*)ptr;
    for (size_t i = 0; i < count+1; i++) {
        printf("%02x ", *(bytes+i));
    }
}

void inverse_bits(void* ptr, size_t offset, size_t count)
{
    if(ptr == NULL || offset + count  > 100)
        return;

    uint8_t* bytes = (uint8_t*)ptr;
    for(size_t i = offset; i < count+offset; i++)
    {
        *(bytes+i) = ~ *(bytes+i);
    }
}

int main() {
    char *text = calloc(101, sizeof(char));
    for(size_t i = 0; i < 101; i++)
        *(text+i) = '\0';
    if (text == NULL)
        return 8;
    printf("Podaj tekst:");
    scanf("%100[^\n]", text);
    show(text, strlen(text));
    inverse_bits(text, 0, strlen(text));
    printf("\n");
    show(text, strlen(text));
    free(text);
    return 0;
}


