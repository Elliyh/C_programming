#ifndef BYTE_SET_H
#define BYTE_SET_H

union byte_set {
    int number;
    unsigned char show_byte[4];
};

#endif