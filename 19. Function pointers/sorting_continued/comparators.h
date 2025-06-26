#ifndef COMPARATORS_H
#define COMPARATORS_H

struct point_t
{
    double x;
    double y;
};

int comp_int(const void *ptr1, const void *ptr2);
int comp_double(const void *ptr1, const void *ptr2);
int comp_point(const void *ptr1, const void *ptr2);
int sort(void *adres, int size, int bytes, int (*comparator)(const void *, const void *));

#endif