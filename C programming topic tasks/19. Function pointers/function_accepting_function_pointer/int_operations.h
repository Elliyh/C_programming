#ifndef INT_OPERATIONS_H
#define INT_OPERATIONS_H

int add_int(int a, int b);
int sub_int(int a, int b);
int div_int(int a, int b);
int mul_int(int a, int b);
int calculate(int a, int b, int (*operation)(int, int));

#endif