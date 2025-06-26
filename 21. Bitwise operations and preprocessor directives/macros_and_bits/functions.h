#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define COUNT_BITS(value, pointer_to_bits_set_counter, pointer_to_bits_cleared_counter) \
{                                                                                       \
    *pointer_to_bits_set_counter = 0;                                                        \
    *pointer_to_bits_cleared_counter = 0;                                                    \
    unsigned long bit_mask = 1;                                                                   \
    long unsigned int i = 1;\
    while(i <= sizeof(value)*8)\
    {                                                                                       \
        if(value & bit_mask)                                                                \
            *pointer_to_bits_set_counter += 1;                                              \
        else                                                                                \
            *pointer_to_bits_cleared_counter += 1;\
        bit_mask *= 2;\
        i++;\
    } \
}



#define DISPLAY_BITS(value) \
{                           \
    unsigned long long bit_mask = 1ULL << sizeof(value)*8-1;       \
    long long unsigned int i = 0;              \
    while(i < sizeof(value)*8)\
    {                                                                                       \
        if(value & bit_mask)                                                                \
            printf("%d", 1);                                              \
        else                                                                                \
            printf("%d", 0);\
        bit_mask >>= 1;\
        i++;\
    }\
}


#define REVERSE_BITS(pointer_to_variable) \
{                                   \
    unsigned long long bit_mask = (unsigned long long)1 << (sizeof(*pointer_to_variable) * 8 - 1); \
    unsigned long long reverse = 0;             \
    for(size_t i = 0; i < sizeof(*pointer_to_variable) * 8; i++) \
    {                       \
        if(*pointer_to_variable & (1ULL << i))              \
        {                               \
            reverse |= bit_mask;                   \
        }                                       \
        bit_mask >>= 1;                          \
    }                                     \
    if(sizeof(*pointer_to_variable) == 4)            \
        *(unsigned int*)(pointer_to_variable) = (unsigned int)reverse; \
    else if(sizeof(*pointer_to_variable) == 2)            \
        *(unsigned short*)(pointer_to_variable) = (unsigned short)reverse; \
    else if(sizeof(*pointer_to_variable) == 8)                \
        *(unsigned long long*)(pointer_to_variable) = (unsigned long long)reverse; \
    else if(sizeof(*pointer_to_variable) == 1)                \
        *(unsigned char*)(pointer_to_variable) = (unsigned char)reverse; \
}

#endif