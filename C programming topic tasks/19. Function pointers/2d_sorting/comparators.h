#ifndef COMPARATORS_H
#define COMPARATORS_H

int comp_min(const int *ptr1, const int *ptr2, int width);
int comp_max(const int *ptr1, const int *ptr2, int width);
int comp_sum(const int *ptr1, const int *ptr2, int width);

int sort_rows(int** tab, int width, int height, int (*function)(const int*, const int*, int));
void free_tab(int** tab, int width, int height);

#endif