#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

#define DEFINE_ARRAY(TYPE) \
  struct array_##TYPE##_t { \
        int size; \
        int capacity; \
        TYPE *data; \
    };\


#define CREATE_ARRAY(TYPE) \
    struct array_##TYPE##_t* create_array_##TYPE(int size)\
    {                      \
       if (size <= 0)      \
            return NULL;   \
       struct array_##TYPE##_t* ukaz = calloc(1, sizeof(struct array_##TYPE##_t)); \
       if(ukaz == NULL)    \
            return NULL;   \
       ukaz->data = calloc(size, sizeof(TYPE));           \
       if(ukaz->data == NULL)                             \
       {                   \
            free(ukaz);     \
            return NULL;\
       }                   \
       ukaz->capacity = size;                             \
       ukaz->size = 0;     \
       return ukaz;\
    }                      \

#define FREE_ARRAY(TYPE) \
    void free_array_##TYPE(struct array_##TYPE##_t *array) \
    {                    \
        if(array == NULL)           \
            return;                \
        if(array->data != NULL)           \
           free(array->data);       \
        free(array);\
    }

#define SAVE_ARRAY(TYPE) \
    int save_array_##TYPE(const struct array_##TYPE##_t *array, const char *filename) \
    {                    \
        if(array == NULL || array->data == NULL || filename == NULL || array->size <= 0 || array->capacity  <= 0 || array->capacity < array->size)                  \
        {                \
            return 1;\
        }                \
        FILE *f = fopen(filename, "wb");                                              \
        if(f == NULL)    \
            return 2;    \
        if(fwrite(&(array->size), sizeof(int), 1, f) != 1)                        \
        {                \
            fclose(f);   \
            return 2;\
        }                \
                         \
        if(fwrite(array->data, sizeof(TYPE), array->size, f) != (size_t)array->size)       \
        {                \
            fclose(f);   \
            return 2;\
        }                \
                         \
        fclose(f) ;                \
                         \
        return 0;                 \
    }

#define LOAD_ARRAY(TYPE) \
    int load_array_##TYPE(struct array_##TYPE##_t **array, const char *filename)\
    {                    \
        if(array == NULL || filename == NULL)                                   \
            {            \
                return 1;           \
            }\
                         \
        FILE *f = fopen(filename, "rb");                                        \
        if(f == NULL)    \
            return 2;    \
                         \
                         \
        int size_data;                   \
        if(fread(&size_data, sizeof(int), 1, f) != 1 || size_data <= 0)                                \
        {                \
            fclose(f);\
            return 3;\
        }                \
                         \
        * array = create_array_##TYPE(size_data);                                    \
                         \
        if(*array == NULL)                                                      \
        {                \
            fclose(f);\
            return 4;\
        }                \
                         \
        if (fread((*array)->data, sizeof(TYPE), size_data, f) != (size_t)size_data) { \
            free_array_##TYPE(*array); \
            fclose(f); \
            return 3; \
        }                \
        (*array)->size = size_data;\
        fclose(f);\
        return 0;\
    }

#define SORT_ARRAY(TYPE)\
    int sort_array_##TYPE(struct array_##TYPE##_t *array)\
    {                   \
        if(array == NULL || array->data == NULL || array->size <= 0 || array->capacity  <= 0 || array->capacity < array->size)                \
            return 1;                \
        for(int i = 0; i < array->size -1; i++)\
        {               \
            for(int j = 0; j < array->size - i - 1; j ++)\
                {       \
                    if(*(array->data+j) > *(array->data+j+1))                                                       \
                    {   \
                        TYPE temp = *(array->data+j);    \
                        *(array->data+j) = *(array->data+j+1);                                                    \
                        *(array->data+j+1) = temp;\
                    }\
                }                \
                        \
        }\
        return 0;\
\
    }







#endif