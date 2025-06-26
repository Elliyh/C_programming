#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

#define CREATE_READ_FUNCTIONS(TYPE, format) \
    int read_##TYPE(TYPE *data, int size)\
    {\
        if(data == NULL || size <= 0)    \
            return 1;                    \
        for(int i = 0; i < size; i++)    \
        {                                \
            if(!scanf(format, (data+i)))\
            {                            \
                return 2;                         \
            }\
        }                                \
        return 0;                                 \
    }                                    \


#define  CREATE_SORT_FUNCTIONS(TYPE) \
    int sort_##TYPE(TYPE *data, int size) \
    {                                \
        if (data == NULL || size <= 0) {                     \
            return 1;                                        \
        }\
        for(int i = 0; i < size-1; i++)   \
        {                            \
            for(int j = 0; j < size-i-1; j++) \
            {                        \
                if(*(data+j) > *(data+j+1))   \
                {                    \
                    TYPE temp = *(data+j);\
                    *(data+j) = *(data+j+1);  \
                    *(data+j+1) = temp;\
                }\
            }\
        }\
        return 0;                              \
    }

#define CREATE_DISPLAY_FUNCTIONS(TYPE, format) \
    void display_##TYPE(const TYPE *data, int size) \
    {                                          \
        if(data == NULL || size <= 0)          \
            return;                          \
        for(int i =0; i < size; i ++)          \
        {                                      \
            printf(format, *(data+i));         \
            printf(" ");                                   \
        }\
    }




#endif