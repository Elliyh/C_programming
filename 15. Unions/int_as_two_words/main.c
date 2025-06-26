#include <stdio.h>
#include "word_set.h"
#include "tested_declarations.h"
#include "rdebug.h"

int main() {
    printf("Podaj liczbe: ");
    union word_set bytes;
    if(!scanf("%d", &bytes.number))
    {
        printf("Incorrect input");
        return 1;
    }
    printf("%d %d", *(bytes.slowo), *(bytes.slowo+1));
    return 0;
}

