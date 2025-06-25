#include <stdio.h>

int main() {
    int tab[] = {67305985, 134678021, 202050057 };
    //1. Ile to będzie bajtów i dlaczego?
    // Będzie 12 bajtów, ponieważ jedna liczba typu int zajmuje 4 bity pamięci
    unsigned char *ukaz = (unsigned char *)tab; // Rzutowanie na wskaźnik bajtowy

    //2. Jakie będą ich wartości?
    for (long unsigned int i = 0; i < sizeof(tab); i++) {
        printf("%u ", *(ukaz + i));
    }
    //3. Każdemy znaczeniu po spacji odpowiada 1 bajt
    // a z pierwszego pytanie wiemy, że mamy tablice typu int, i jedna liczba zajmuje 4 bity,
    // co oznacza, że 4 kolejnym bitam odpowiada jedne znacznie z tablicy tab.
    return 0;
}
