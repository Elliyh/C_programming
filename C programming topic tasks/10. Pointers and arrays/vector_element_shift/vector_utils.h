#ifndef VECTOR_UTILS_H
#define VECTOR_UTILS_H


enum direction
{
    ROTATE_RIGHT,
    ROTATE_LEFT
};

void swap(int *a, int *b);
int read_vector(int vec[], int size, int stop_value);
void display_vector(const int vec[], int size);
int shift(int *array, int array_size, int positions_to_shift, enum direction dir);

#endif