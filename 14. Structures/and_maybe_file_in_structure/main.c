#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "tested_declarations.h"
#include "rdebug.h"

struct file_t
{
    FILE *f;
    int size;
};

void close_file(struct file_t* f)
{
    if(f != NULL && f->f != NULL)
        fclose(f->f);
}

int open_file(struct file_t* f, const char *filename)
{
    if(f == NULL || filename == NULL)
        return 1;
    /*if(f->f == NULL)
        return 2;*/
    FILE *file = fopen(filename, "a+");
    if (file == NULL)
    {
        return 2;
    }
    else
    {
        fseek(file, 0, SEEK_END);
        int size_of_file = ftell(file);
        f->size = size_of_file;
        f->f = file;
    }
    return 0;
}

struct file_t* find_min(const struct file_t* files, int size)
{
    if (files == NULL || size <= 0)
    {
        return NULL;
    }
    int g = 0;
    int min = (files+g)->size;
    struct file_t* ukaz = (struct file_t*)files+g;
    for (; g < size; g++)
    {
        if (min > (files+g)->size)
        {
            min = (files+g)->size;
            ukaz = (struct file_t*)(files+g);
        }
    }
    return ukaz;
}



int main() {
    char names_files [1000] = {'\0'};
    struct file_t my_struct[5];
    char tekst[1000] = {'\0'};
    int i;
    printf("Podaj nazwy plikow:\n");
    char s1;
    for (i = 0; i < 5; i++) {
        if (scanf("%999[^\n]", names_files) != 1) {
            break;
        }
        else
        {
            FILE *f = fopen(names_files, "r");
            if (f == NULL)
            {
                i--;
                for(int h = 0; h < 1000; h++)
                {
                    *(names_files+h) = '\0';
                }
                getchar();
                continue;
            }
            else
            {
                fclose(f);
            }
            int spraw = open_file(my_struct+i, (char *)names_files);
            for(int h = 0; h < 1000; h++)
            {
                *(names_files+h) = '\0';
            }
            if (spraw == 1 || spraw == 2)
            {
                for(int j = 0; j < i; j++)
                {
                    close_file(my_struct+i);
                }
                printf("Couldn't open file");
                return 4;
            }
        }
        getchar();
    }
    if ((s1 = getchar()) == '\n' && i>= 5)
    {
    }
    else if(i>= 5)
    {
        ungetc(s1, stdin);
        do {
            if((s1 = getchar()) == '\n')
            {}
            else
                ungetc(s1, stdin);
        }while(getchar() != '\n'); //(s1 = getchar()) != '\n'
    }
    if (i == 0)
    {
        printf("Couldn't open file");
        return 4;
    }
    printf("Podaj teksty:\n");
    int spraw = scanf("%999[^\n]", tekst);
    while(spraw != 0)
    {
        getchar();
        struct file_t* ukaz = find_min(my_struct, i);
        if(ukaz == NULL)
        {
            for(int j = 0; j < i; j++)
            {
                close_file(my_struct+i);
            }
            printf("Couldn't open file");
            return 4;
        }
        fputs(tekst, ukaz->f);
        fputc('\n', ukaz->f);
        //fwrite(tekst, sizeof(char), strlen(tekst), ukaz->f);
        ukaz->size = ftell(ukaz->f);
        for(int j = 0; j < 1000; j++)
            *(tekst+j) = '\0';
        if ((s1 = getchar()) == '\n')
        {
            break;
        }
        else
        {
            ungetc(s1, stdin);
        }
        spraw = scanf("%999[^\n]", tekst);
    }

    for(int j = 0; j < i; j++)
    {
        close_file(my_struct+j);
    }
    printf("Files saved");
    return 0;
}


/*
clock.txt
one.txt
//../industry.txt

Dolor modi quaerat sed etincidunt. Porro est consectetur dolorem neque. Adipisci magnam quiquia neque quiquia dolorem. Quaerat labore non voluptatem labore amet dolorem. Consectetur etincidunt dolore quaerat sed. Tempora sed numquam est dolorem modi magnam sed. Eius quiquia adipisci quisquam dolore neque aliquam dolor. Sed magnam ipsum sit dolore magnam est. Non dolore neque quiquia adipisci dolorem.
Porro tempora quaerat dolor numquam tempora. Amet velit numquam quisquam dolorem labore. Quisquam sit ut dolore sed neque. Dolore labore eius consectetur eius adipisci dolore adipisci. Magnam sit consectetur quiquia magnam etincidunt voluptatem velit. Dolore est sed dolore. Eius dolorem labore velit. Numquam porro ipsum sit quiquia velit. Quiquia porro eius amet est dolore porro.
Labore est sit dolor modi dolor sed. Dolore etincidunt etincidunt dolorem tempora porro. Etincidunt dolore magnam sed amet. Est dolore non velit. Est quiquia porro magnam est porro quisquam dolore. Sit numquam dolorem magnam. Dolor consectetur dolorem aliquam consectetur dolore eius. Aliquam neque sed aliquam dolor eius numquam velit. Amet numquam quiquia dolor consectetur est labore.
Porro modi amet velit non. Sit numquam velit ut aliquam. Sit dolor adipisci magnam ut adipisci dolor quaerat. Numquam quiquia voluptatem voluptatem est sit consectetur. Quiquia non dolor numquam sit non.
Neque sed consectetur dolore. Sit numquam amet sit aliquam amet. Tempora sed porro adipisci ipsum. Dolorem non ipsum aliquam dolore magnam. Sed sit neque eius quiquia tempora. Modi porro magnam numquam numquam porro aliquam porro. Quisquam quisquam numquam neque neque ipsum amet tempora. Non ipsum voluptatem dolorem quiquia labore.
Dolorem quaerat ut quaerat. Voluptatem dolor eius non quaerat consectetur. Ipsum quiquia ut neque. Adipisci ipsum porro porro dolorem amet ipsum sit. Consectetur tempora sit velit eius est ipsum.
Ut ut eius sit quisquam ut. Porro porro labore quaerat porro amet dolorem aliquam. Modi consectetur labore labore. Amet adipisci dolore amet dolore etincidunt neque. Dolore magnam quisquam est.
Tempora voluptatem non quaerat dolor porro. Aliquam dolore etincidunt sit non. Est etincidunt ipsum numquam sit ipsum. Ipsum dolorem quisquam est voluptatem. Dolore non magnam amet dolor ut consectetur. Amet modi quiquia labore voluptatem quisquam dolor.
Aliquam eius quaerat tempora porro adipisci est. Quaerat non dolore eius. Dolore non quaerat ipsum labore. Non amet neque voluptatem numquam quiquia magnam labore. Labore est sit ut.
Etincidunt neque quisquam non quisquam. Numquam velit porro adipisci consectetur eius. Labore etincidunt modi dolore sit. Non adipisci quiquia amet eius ut voluptatem est. Quisquam modi dolorem dolore dolorem. Dolore consectetur consectetur etincidunt consectetur.
Dolor aliquam aliquam sed modi. Quisquam non consectetur numquam sed consectetur neque. Ut magnam sed numquam eius. Dolore aliquam non quaerat. Dolorem quaerat dolore est dolorem consectetur.
Numquam non sit modi magnam voluptatem magnam. Quisquam sed dolore sit dolorem quaerat etincidunt. Numquam dolore amet modi. Dolor amet numquam sed quiquia ut. Dolor porro numquam modi porro adipisci neque adipisci. Est ipsum voluptatem sed sed amet etincidunt. Ut sit ipsum adipisci. Porro neque dolore tempora neque. Labore sed adipisci eius sed sed adipisci quisquam.
Ipsum sit non sit est ipsum modi. Ipsum adipisci ipsum tempora porro velit aliquam. Porro sed sed quisquam dolorem amet tempora. Porro est etincidunt neque dolor tempora quisquam. Modi velit magnam eius porro quiquia quaerat sed. Velit velit modi etincidunt neque velit sed labore. Sed dolore aliquam consectetur neque. Eius voluptatem neque neque etincidunt sed etincidunt dolore. Tempora est quaerat tempora labore ipsum.
Quaerat consectetur neque quaerat. Aliquam quisquam magnam quiquia ipsum. Magnam non velit non voluptatem quisquam. Sit labore aliquam magnam amet etincidunt sed aliquam. Est quisquam neque labore amet quaerat porro. Sed dolor quiquia dolore.
Quisquam sit neque velit neque eius dolore. Quaerat porro quisquam sed tempora dolor. Quisquam dolor porro quiquia non quaerat aliquam. Dolor ipsum adipisci dolorem sit porro. Dolore sit quisquam velit. Porro ut est modi quisquam. Sit tempora sit tempora sit dolore. Magnam dolore amet porro consectetur eius sed. Ipsum non dolor porro velit sed adipisci consectetur.
Velit quiquia etincidunt porro. Ut adipisci quiquia voluptatem magnam dolorem ipsum. Sed sed eius sit quiquia consectetur quaerat porro. Quiquia non amet tempora dolorem quisquam dolore. Velit porro est amet magnam consectetur dolor.
Aliquam quisquam consectetur aliquam sit modi amet est. Non neque eius numquam. Ut magnam consectetur modi numquam quisquam. Quisquam sit dolor porro. Numquam adipisci dolor dolore sed magnam est. Neque dolor quaerat neque porro sed. Sit magnam porro numquam. Consectetur voluptatem numquam dolorem voluptatem eius ut.
 */
