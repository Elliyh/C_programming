#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"
#include "tested_declarations.h"
#include "rdebug.h"


int main() {

    struct doubly_linked_list_t* ukaz = dll_create();

    if(ukaz == NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    int spraw, number, value, index, err_code, size;
    struct node_t* temp;
    while(1)
    {
        printf("Co chcesz zrobic?");

        int choice;
        if(!scanf("%d", &choice))
        {
            printf("Incorrect input");
            dll_clear(ukaz);
            free(ukaz);
            return 1;
        }

        switch (choice) {
            case 0:
                dll_clear(ukaz);
                free(ukaz);
                return 0;
            case 1:
                printf("Podaj liczbe");
                if(!scanf("%d", &value))
                {
                    printf("Incorrect input");
                    dll_clear(ukaz);
                    free(ukaz);
                    return 1;
                }
                spraw = dll_push_back(ukaz, value);
                if(spraw == 2)
                {
                    printf("Failed to allocate memory");
                    dll_clear(ukaz);
                    free(ukaz);
                    return 8;
                }
                break;
            case 2:
                spraw = dll_is_empty(ukaz);
                if(spraw == 1)
                {
                    printf("List is empty\n");
                    break;
                }
                number = dll_pop_back(ukaz, NULL);
                printf("%d\n", number);
                break;
            case 3:
                printf("Podaj liczbe");
                if(!scanf("%d", &value))
                {
                    printf("Incorrect input");
                    dll_clear(ukaz);
                    free(ukaz);
                    return 1;
                }
                spraw = dll_push_front(ukaz, value);
                if(spraw == 2)
                {
                    printf("Failed to allocate memory");
                    dll_clear(ukaz);
                    free(ukaz);
                    return 8;
                }
                break;
            case 4:
                spraw = dll_is_empty(ukaz);
                if(spraw == 1)
                {
                    printf("List is empty\n");
                    break;
                }
                number = dll_pop_front(ukaz, NULL);
                printf("%d\n", number);
                break;
            case 5:
                printf("Podaj liczbe");
                if(!scanf("%d", &value))
                {
                    printf("Incorrect input");
                    dll_clear(ukaz);
                    free(ukaz);
                    return 1;
                }
                printf("Podaj index");
                if(!scanf("%d", &index))
                {
                    printf("Incorrect input");
                    dll_clear(ukaz);
                    free(ukaz);
                    return 1;
                }
                spraw = dll_insert(ukaz, index, value);
                if(spraw == 1)
                {
                    printf("Index out of range\n");
                    break;
                }
                if(spraw == 2)
                {
                    printf("Failed to allocate memory");
                    dll_clear(ukaz);
                    free(ukaz);
                    return 8;
                }
                break;
            case 6:
                spraw = dll_is_empty(ukaz);
                if(spraw == 1)
                {
                    printf("List is empty\n");
                    break;
                }
                printf("Podaj index");
                if(!scanf("%d", &index))
                {
                    printf("Incorrect input");
                    dll_clear(ukaz);
                    free(ukaz);
                    return 1;
                }
                number = dll_remove(ukaz, index, &err_code);
                if(err_code == 1)
                {
                    printf("Index out of range\n");
                    break;
                }
                printf("%d\n", number);
                break;
            case 7:
                spraw = dll_is_empty(ukaz);
                if(spraw == 1)
                {
                    printf("List is empty\n");
                    break;
                }
                temp = dll_end(ukaz);
                printf("%d\n", temp->data);
                break;
            case 8:
                spraw = dll_is_empty(ukaz);
                if(spraw == 1)
                {
                    printf("List is empty\n");
                    break;
                }
                temp = dll_begin(ukaz);
                printf("%d\n", temp->data);
                break;
            case 9:
                spraw = dll_is_empty(ukaz);
                printf("%d\n", spraw);
                break;
            case 10:
                size = dll_size(ukaz);
                printf("%d\n", size);
                break;
            case 11:
                dll_clear(ukaz);
                break;
            case 12:
                spraw = dll_is_empty(ukaz);
                if(spraw == 1)
                {
                    printf("List is empty\n");
                    break;
                }
                printf("Podaj index");
                if(!scanf("%d", &index))
                {
                    printf("Incorrect input");
                    dll_clear(ukaz);
                    free(ukaz);
                    return 1;
                }
                number = dll_at(ukaz, index, &err_code);
                if(err_code == 1)
                {
                    printf("Index out of range\n");
                    break;
                }
                printf("%d\n", number);
                break;
            case 13:
                spraw = dll_is_empty(ukaz);
                if(spraw == 1)
                {
                    printf("List is empty\n");
                    break;
                }
                dll_display(ukaz);
                printf("\n");
                break;
            case 14:
                spraw = dll_is_empty(ukaz);
                if(spraw == 1)
                {
                    printf("List is empty\n");
                    break;
                }
                dll_display_reverse(ukaz);
                printf("\n");
                break;
            default:
                printf("Incorrect input data\n");
                break;
        }
    }
}


