#include "types_utils.h"
#ifndef SORT_H
#define SORT_H


int quicksort_asc(int l, int r, int tab[], int tabSize);
int quicksort_desc(int l, int r, int tab[], int tabSize);
int quicksort(int tab[], int size, enum direction dir);

#endif