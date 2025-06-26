#ifndef INT_OPERATIONS_H
#define INT_OPERATIONS_H

enum tryb {
    op_add,
    op_sub,
    op_div,
    op_mul
};

int add_int(int a, int b);
int sub_int(int a, int b);
int div_int(int a, int b);
int mul_int(int a, int b);

int (*get_function(enum tryb operation))(int, int);

#endif