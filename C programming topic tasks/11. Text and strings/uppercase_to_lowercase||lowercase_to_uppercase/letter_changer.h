#ifndef LETTER_CHANGER_H
#define LETTER_CHANGER_H

enum letter_changer_t
{
    TO_UPPER,
    TO_LOWER
};

char* change_letter_size(char *txt, enum letter_changer_t c);
char to_lower(char sym);
char to_upper(char sym);

#endif