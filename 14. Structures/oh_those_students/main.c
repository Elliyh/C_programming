#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"


struct student_t {
    char name[20];
    char surname[40];
    int index;
};



struct student_t* read(struct student_t* p, int *err_code)
{
    if(p == NULL)
    {
        if (err_code != NULL)
            *err_code = 1;
        return NULL;
    }

    int roz = 0;
    char sym;
    while ((sym = getchar()) == ' '){
        roz++;
    }
    if (roz >= 0)
        ungetc(sym, stdin);

    int spraw = scanf("%20[^, ]", p->name);

    while((sym = getchar()) != ',')
    {
        if (sym == '\n' || sym == ' ')
        {
            if (err_code != NULL)
                *err_code = 1;
            return NULL;
        }
    }
    ungetc(sym, stdin);

    spraw += scanf(", %40[^,\n]", p->surname);


    if (spraw == 1)
    {
        if (err_code != NULL)
            *err_code = 2;
        return NULL;
    }


    while ((sym = getchar()) != ','){
        if(sym == '\n')
        {
            if (err_code != NULL)
                *err_code = 2;
            return NULL;
        }
        /*if (sym == '\n')
        {
            if (err_code != NULL)
                *err_code = 3;
            return NULL;
        }*/
    }
    spraw += scanf("%d", &p->index);

    if (spraw == 2)
    {
        if (err_code != NULL)
            *err_code = 3;
        return NULL;
    }
    if (err_code != NULL)
        *err_code = 0;
    return p;


}


void show(const struct student_t* p)
{
    if (p != NULL)
        printf("%s %s, %d", p->name, p->surname, p->index);
}

int main() {
    int err_code;
    struct student_t person;
    printf("Podaj dane:\n");
    if(read(&person, &err_code)==NULL || err_code != 0)
    {
        printf("Incorrect input");
        return err_code;
    }
    show(&person);
    return 0;
}

