#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

union bit_set {
    uint8_t my_byte;
    struct {
        uint8_t b0: 1;
        uint8_t b1: 1;
        uint8_t b2: 1;
        uint8_t b3: 1;
        uint8_t b4: 1;
        uint8_t b5: 1;
        uint8_t b6: 1;
        uint8_t b7: 1;
    };
};


void display_console(uint8_t *ukaz) {
    int i, j;
    for (i = 0; i < 40; i++) {
        for (j = 7; j >= 0; j--) {
            union bit_set byte;
            byte.my_byte = *(ukaz + i);
            //printf("%c", byte.my_byte & (1<< j)?'#':' ');
            switch (j) {
                case 7:
                    if (byte.b7) {
                        printf("#");
                    } else {
                        printf(" ");
                    }
                    break;
                case 6:
                    if (byte.b6) {
                        printf("#");
                    } else {
                        printf(" ");
                    }
                    break;
                case 5:
                    if (byte.b5) {
                        printf("#");
                    } else {
                        printf(" ");}
                    break;
                case 4:
                    if (byte.b4) {
                        printf("#");
                    } else {
                        printf(" ");
                    }
                    break;
                case 3:
                    if (byte.b3) {
                        printf("#");
                    } else {
                        printf(" ");
                    }
                    break;
                case 2:
                    if (byte.b2) {
                        printf("#");
                    } else {
                        printf(" ");
                    }
                    break;
                case 1:
                    if (byte.b1) {
                        printf("#");
                    } else {
                        printf(" ");
                    }
                    break;
                case 0:
                    if (byte.b0) {
                        printf("#");
                    } else {
                        printf(" ");
                    }
                    break;
            }
        }
        if (i % 5 == 4 && i != 39)
        {
            printf("\n");
        }

    }
}

void write_file(FILE *f, uint8_t *ukaz) {
    int i, j;
    for (i = 0; i < 40; i++) {
        for (j = 7; j >= 0; j--) {
            union bit_set byte;
            byte.my_byte = *(ukaz + i);
            //printf("%c", byte.my_byte & (1<< j)?'#':' ');
            switch (j) {
                case 7:
                    if (byte.b7) {
                        fprintf(f, "#");
                    } else {
                        fprintf(f, " ");
                    }
                    break;
                case 6:
                    if (byte.b6) {
                        fprintf(f, "#");
                    } else {
                        fprintf(f, " ");
                    }
                    break;
                case 5:
                    if (byte.b5) {
                        fprintf(f, "#");
                    } else {
                        fprintf(f, " ");
                    }
                    break;
                case 4:
                    if (byte.b4) {
                        fprintf(f, "#");
                    } else {
                        fprintf(f, " ");
                    }
                    break;
                case 3:
                    if (byte.b3) {
                        fprintf(f, "#");
                    } else {
                        fprintf(f, " ");
                    }
                    break;
                case 2:
                    if (byte.b2) {
                        fprintf(f, "#");
                    } else {
                        fprintf(f, " ");
                    }
                    break;
                case 1:
                    if (byte.b1) {
                        fprintf(f, "#");
                    } else {
                        fprintf(f, " ");
                    }
                    break;
                case 0:
                    if (byte.b0) {

                        fprintf(f, "#");
                    } else {
                        fprintf(f, " ");
                    }
                    break;
            }
        }
        if (i % 5 == 4 && i != 39)
        {
            fprintf(f, "\n");
        }

    }
}


int main() {
    printf("Enter values: ");
    uint8_t *ukaz = calloc(400, sizeof(uint8_t));
    if (ukaz == NULL) {
        printf("Failed to allocate memory");
        return 8;
    }
    int i;
    for (i = 0; i < 40; i++) {
        if (!scanf("%hhx", ukaz + i)) {
            printf("Incorrect input");
            free(ukaz);
            return 1;
        }
    }
    for (i = 0; i < 40; i++) {
        printf("%hhx ", *(ukaz + i));
    }
    char *filename = calloc(50, sizeof(char));
    if (filename == NULL) {
        printf("Failed to allocate memory");
        free(ukaz);
        return 8;
    }
    while((getchar()) != '\n');
    printf("\nPodaj nazwe pliku: ");
    scanf("%39[^\n]", filename);
    display_console(ukaz);
    FILE *f = fopen(filename, "w");
    if (f == NULL) {
        printf("\nCouldn't create file");
        free(ukaz);
        free(filename);
        return 5;
    }

    write_file(f, ukaz);
    printf("\nFile saved");
    fclose(f);
    free(ukaz);
    free(filename);
    return 0;
}

