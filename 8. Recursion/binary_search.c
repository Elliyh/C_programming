#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

int data_input(int vec[], int size)
{
    if (size == 0)
    {
        return 0;
    }
    if (vec[size]<vec[size-1])
        return 1;
    return data_input(vec, size-1);
}

int read_vector(int vec[], int size, int stop_value)
{
    int i;
    int rozmiar = 0;
    if (size <= 0)
        return -1;
    for (i = 0; i < size; i++)
    {
        if (scanf("%d", &vec[rozmiar]) == 1)
        {

            if (vec[rozmiar] == stop_value)
            {
                break;
            }
            rozmiar += 1;

        }
        else
            return -2;
    }

    if (i <= size)
    {
        int a;
        while((a=getchar()) != '\n'){}
    }

    return rozmiar;

}


int binary_search(const int arr[], int l, int r, int x)
{
    if (arr[l] == x)
        return l;
    if (l == r)
    {
        if (arr[l] == x)
            return l;
        else
            return -1;
    }
    if (l+1 == r || l == r-1)
    {
        if (arr[l+1] == x)
            return l+1;
        if (arr[r-1] == x)
            return r-1;
        else
            return -1;
    }
    int sred = (l+r)/2;
    if (x >= arr[l] && x <= arr[sred])
    {
        return binary_search(arr, l, sred, x);
    }
    if (x >= arr[sred] && x <= arr[r-1])
    {
        return binary_search(arr, sred, r, x);
    }
    if (arr[r] == x)
        return r;
    return -1;
}


int main() {
    int wektor [150];
    printf("podaj pierwszy wektor:");
    int prov_vec = read_vector(wektor, 150, 0);
    if (prov_vec == -2)
    {
        printf("Incorrect input");
        return 1;
    }
    else if (prov_vec == -1 || prov_vec == 0)
    {
        printf("Not enough data available");
        return 3;
    }
    /*else if (wektor[0] > wektor[1])
    {
        printf("Incorrect input data");
        return 2;
    }*/
    printf("podaj szukany element:");
    int find_element;
    if (!scanf("%d", &find_element))
    {
        printf("Incorrect input");
        return 1;
    }
    if (data_input(wektor, prov_vec-1))
    {
        printf("Incorrect input data");
        return 2;
    }
    printf("%d", binary_search(wektor, 0, prov_vec,find_element));
    //printf("\n%d", binary_search((int[]){-1000, -996, -983, -946, -942, -937, -929, -922, -920, -909, -907, -904, -900, -894, -885, -878, -869, -861, -859, -849, -831, -826, -825, -803, -799, -793, -749, -738, -719, -718, -709, -702, -701, -695, -694, -691, -676, -667, -665, -658, -646, -645, -642, -641, -637, -623, -615, -602, -585, -582, -559, -558, -555, -551, -540, -537, -532, -530, -525, -522, -519, -501, -472, -465, -462, -461, -424, -421, -414, -401, -337, -333, -328, -327, -317, -312, -310, -272, -270, -268, -262, -261, -233, -230, -228, -227, -201, -192, -187, -185, -179, -178, -155, -153, -148, -138, -137, -131, -123, -113, -106, -99, -98, -97, -89, -73, -69, -64, -59, -57, -54, -52, -43, -40, -38, -27, -17, -13, -2, 0, 12, 43, 44, 45, 49, 82, 87, 115, 125, 131, 136, 140, 141, 142, 143, 145, 150, 160, 168, 170, 183, 189, 197, 207, 208, 209, 212, 230, 233, 237, 255, 264, 275, 280, 303, 312, 316, 317, 336, 363, 375, 382, 413, 427, 430, 451, 462, 465, 481, 489, 495, 496, 499, 510, 516, 523, 527, 537, 541, 543, 546, 562, 571, 582, 595, 596, 600, 605, 611, 619, 620, 621, 634, 659, 666, 670, 703, 726, 728, 731, 732, 733, 747, 749, 753, 765, 767, 771, 778, 785, 797, 805, 812, 832, 837, 840, 858, 860, 871, 873, 874, 875, 888, 905, 927, 938, 953, 968, 970, 972, 973, 981, 999}, 0, 233, -358));
    return 0;
}

