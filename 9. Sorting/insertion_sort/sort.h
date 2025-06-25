
#ifndef SORT_H
#define SORT_H

enum direction {
    ASCENDING = 0,
    DESCENDING = 1
};
int insertion_sort_asc(int tab[], int size);
int insertion_sort_desc(int tab[], int size);
int insertion_sort(int tab[], int size, enum direction dir);

#endif