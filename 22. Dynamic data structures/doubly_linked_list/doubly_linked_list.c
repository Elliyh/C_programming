#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"
#include "tested_declarations.h"
#include "rdebug.h"

struct doubly_linked_list_t* dll_create()
{
    struct doubly_linked_list_t* ukaz = calloc(1, sizeof(struct doubly_linked_list_t));
    if(!ukaz)
        return NULL;
    ukaz->head = NULL;
    ukaz->tail = NULL;
    return ukaz;
}

int dll_push_back(struct doubly_linked_list_t* dll, int value)
{
    if(!dll)
        return 1;
    struct node_t* temp  = calloc(1, sizeof(struct node_t));
    if(temp == NULL)
        return 2;
    temp->data = value;
    temp->next = NULL;
    temp->prev = dll->tail;
    if(dll->head == NULL)
    {
        dll->head = temp;
    }
    if(dll->tail != NULL)
    {
        dll->tail->next = temp;

    }
    dll->tail = temp;
    return 0;
}


int dll_push_front(struct doubly_linked_list_t* dll, int value)
{
    if(dll == NULL)
        return 1;
    struct node_t* temp  = calloc(1, sizeof(struct node_t));
    if(temp == NULL)
        return 2;
    temp->data = value;
    temp->next = dll->head;
    temp->prev = NULL;
    if(dll->tail == NULL)
        dll->tail = temp;
    if(dll->head != NULL)
        dll->head->prev = temp;
    dll->head= temp;
    return 0;
}
int dll_pop_front(struct doubly_linked_list_t* dll, int *err_code)
{
    if(dll == NULL || dll->head == NULL)
    {
        if(err_code != NULL)
            *err_code = 1;
        return 1;
    }
    if(dll->tail == dll->head)
    {
        int number = dll->tail->data;
        free(dll->tail);
        dll->tail = NULL;
        dll->head = NULL;
        if(err_code != NULL)
            *err_code = 0;
        return number;
    }
    int number = dll->head->data;
    struct node_t* temp = dll->head;
    if(dll->head->next != NULL)
        (dll->head->next)->prev = NULL;
    dll->head = dll->head->next;
    free(temp);
    if(err_code != NULL)
        *err_code = 0;
    return number;
}

int dll_pop_back(struct doubly_linked_list_t* dll, int *err_code)
{
    if(dll == NULL || dll->tail == NULL)
    {
        if(err_code != NULL)
            *err_code = 1;
        return 1;
    }
    if(dll->tail == dll->head)
    {
        int number = dll->tail->data;
        free(dll->tail);
        dll->tail = NULL;
        dll->head = NULL;
        if(err_code != NULL)
            *err_code = 0;
        return number;
    }
    int number = dll->tail->data;
    struct node_t* temp = dll->tail;
    if(dll->tail->prev != NULL)
        (dll->tail->prev)->next = NULL;
    dll->tail = dll->tail->prev;
    free(temp);
    if(err_code != NULL)
        *err_code = 0;
    return number;
}

int dll_back(const struct doubly_linked_list_t* dll, int *err_code)
{
    if(dll == NULL || dll->tail == NULL)
    {
        if(err_code != NULL)
            *err_code = 1;
        return 1;
    }
    int number = dll->tail->data;
    if(err_code != NULL)
        *err_code = 0;
    return number;
}
int dll_front(const struct doubly_linked_list_t* dll, int *err_code)
{
    if(dll == NULL || dll->head == NULL)
    {
        if(err_code != NULL)
            *err_code = 1;
        return 1;
    }
    int number = dll->head->data;
    if(err_code != NULL)
        *err_code = 0;
    return number;
}

struct node_t* dll_begin(struct doubly_linked_list_t* dll)
{
    if(dll == NULL || dll->head == NULL)
        return NULL;
    return dll->head;
}
struct node_t* dll_end(struct doubly_linked_list_t* dll)
{
    if(dll == NULL || dll->tail == NULL)
        return NULL;
    return dll->tail;
}

int dll_size(const struct doubly_linked_list_t* dll)
{
    if(dll == NULL)
        return -1;
    if(dll->tail == NULL && dll->head == NULL)
    {
        return 0;
    }
    int count = 0;
    struct node_t* temp = dll->head;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
int dll_is_empty(const struct doubly_linked_list_t* dll)
{
    if(dll == NULL)
        return -1;
    if(dll->head == NULL || dll->tail == NULL)
        return 1;
    return 0;
}

int dll_at(const struct doubly_linked_list_t* dll, unsigned int index, int *err_code)
{
    if(dll == NULL || dll->head == NULL || dll->tail == NULL
    || (int)index < 0 || (int)index >= dll_size(dll))
    {
        if(err_code != NULL)
            *err_code = 1;
        return 1;
    }
    int count = 0;
    struct node_t* temp = dll->head;
    while(count < (int)index)
    {
        count++;
        temp = temp->next;
    }
    if(err_code != NULL)
        *err_code = 0;
    return temp->data;
}

int dll_insert(struct doubly_linked_list_t* dll, unsigned int index, int value)
{
    if(dll == NULL || (int)index < 0 || (int)index > dll_size(dll))
    {
        return 1;
    }
    struct node_t* temp  = calloc(1, sizeof(struct node_t));
    if(temp == NULL)
        return 2;
    int count = 0;
    struct node_t* move = dll->head;
    while(count < (int)index-1)
    {
        count++;
        move = move->next;
    }
    temp->data = value;
    if(index == 0)
    {
        temp->next = move;
        if(move != NULL)
        {
            temp->prev = move->prev;
            move->prev = temp;
        }
    }
    else
    {
        temp->next = move->next;
        temp->prev = move;
        if(move->next != NULL)
            move->next->prev = temp;

        move->next = temp;
    }
    if (temp->next == NULL)
        dll->tail = temp;
    if (temp->prev == NULL)
        dll->head = temp;
    return 0;
}

int dll_remove(struct doubly_linked_list_t* dll, unsigned int index, int *err_code)
{
    if(dll == NULL || dll->head == NULL || dll->tail == NULL || (int)index < 0 || (int)index > dll_size(dll))
    {
        if(err_code != NULL)
            *err_code = 1;
        return 1;
    }
    int count = 0;
    struct node_t* move = dll->head;
    while(count < (int)index)
    {
        count++;
        move = move->next;
    }
    int number = move->data;
    if(count == 0)
    {
        if(move->next != NULL)
        {
            move->next->prev = NULL;
        }
        if (move->next == NULL)
            dll->tail = move->prev;
        if (move->prev == NULL)
            dll->head = move->next;
        free(move);
    }
    else
    {
        if(move->next != NULL)
        {
            move->next->prev = move->prev;
        }
        if(move->prev != NULL)
        {
            move->prev->next = move->next;
        }
        if (move->next == NULL)
            dll->tail = move->prev;
        if (move->prev == NULL)
            dll->head = move->next;
        free(move);
    }
    if(err_code != NULL)
        *err_code = 0;
    return number;
}

void dll_clear(struct doubly_linked_list_t* dll)
{
    if(dll == NULL || dll->head == NULL || dll->tail == NULL)
    {
        return;
    }
    struct node_t* temp = dll->head;
    while(temp != NULL)
    {
        struct node_t* temp_2 = temp;
        temp = temp->next;
        free(temp_2);
    }
    dll->head = NULL;
    dll->tail = NULL;

}

void dll_display(const struct doubly_linked_list_t* dll)
{
    if(dll == NULL || dll->head == NULL || dll->tail == NULL)
        return;
    struct node_t* temp = dll->head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
void dll_display_reverse(const struct doubly_linked_list_t* dll)
{
    if(dll == NULL || dll->head == NULL || dll->tail == NULL)
        return;
    struct node_t* temp = dll->tail;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
}

