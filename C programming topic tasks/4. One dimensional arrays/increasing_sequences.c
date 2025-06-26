#include <stdio.h>

int main() {
    printf("Podaj liczby:");
    int masiv[1000] = {0};
    int proverka = 0;
    int i;
    for (i = 0; i < 1000; i++) {
        if (scanf("%d", &masiv[i])) {
            proverka += 1; //zapoln masiva 0
        }
        if (masiv[i] == 0)
            break;
    }
    if (proverka != i + 1 && masiv[i] == 0 && proverka != 1000) {
        printf("Incorrect input"); //proverka vvoda i zakon na 0 odnovremenno
        return 1;
    }
    int pod_masivy[500][1002];
    for (int k = 0; k < 500; k++) {
        for (int p = 0; p < 1002; p++) { //tyt bylo 1002!!!!!!!!!!!!!!!
            pod_masivy[k][p] = 0; // zapolnienie novogo massiva 0
        }
    }
    int por_elemen_new = 0; // perv adres
    int por_elemen_new_1 = 0; // vtor adres
    int kol_elemen_v_podmas = 0; // nahya?
    int j;
    for (j = 0; (masiv[j + 1] != 0 && j < 1000 && masiv[j] <= masiv[j + 1])
    || (masiv[j] > masiv[j + 1] && masiv [j+1] == 0 && j < 1000) || (masiv[j] > masiv[j + 1] && masiv [j+1] != 0
    && j < 1000); j++)
    {
        if (masiv[j] == masiv[j+1])
        {
            pod_masivy[por_elemen_new][por_elemen_new_1] = masiv[j];
            kol_elemen_v_podmas += 1;
            pod_masivy[por_elemen_new][1000] = kol_elemen_v_podmas;
            kol_elemen_v_podmas = 0; //XZ?
            por_elemen_new += 1;
            por_elemen_new_1 = 0;
            continue;
        }
        if (masiv[j] < masiv[j + 1] && masiv[j+1] != 0) {
            if (kol_elemen_v_podmas == 0) {
                pod_masivy[por_elemen_new][1001] = j; // poryadk nomer first elementa, xotyua mozna
                // na 1000 iba 0 - 999 = 1000
            }
            pod_masivy[por_elemen_new][por_elemen_new_1] = masiv[j];
            kol_elemen_v_podmas += 1; // xz?
            por_elemen_new_1 += 1;
            pod_masivy[por_elemen_new][1000] = kol_elemen_v_podmas;

        }
        else if ((masiv[j] > masiv[j + 1] && masiv [j+1] == 0) || (masiv[j] > masiv[j + 1] && masiv [j+1] != 0)){
            if (masiv[j] > masiv[j + 1] && masiv [j+1] != 0)
            {
                if (pod_masivy[por_elemen_new][1000] == 0)
                {
                    continue;
                }
                pod_masivy[por_elemen_new][por_elemen_new_1] = masiv[j];
                kol_elemen_v_podmas += 1;
                pod_masivy[por_elemen_new][1000] = kol_elemen_v_podmas;
                kol_elemen_v_podmas = 0; //XZ?
                por_elemen_new += 1;
                por_elemen_new_1 = 0;
            }
            else if (masiv [j+1] == 0)
            {
                pod_masivy[por_elemen_new][por_elemen_new_1] = masiv[j];
                break;
            }

            /*pod_masivy[por_elemen_new][por_elemen_new_1] = masiv[j];
            kol_elemen_v_podmas += 1;
            pod_masivy[por_elemen_new][1000] = kol_elemen_v_podmas; // kol elem v maks podmasive
            kol_elemen_v_podmas = 0; //XZ?
            por_elemen_new += 1;
            por_elemen_new_1 = 0;*/
        }
    }
    //pod_masivy[por_elemen_new][por_elemen_new_1] = masiv[j]; // dlya pryam last elementa chto nie byl sverhu


    /*if (kol_elemen_v_podmas < 1000)
    {
        kol_elemen_v_podmas += 1;
    }*/
    if (masiv [j+1] == 0)
    {
        pod_masivy[por_elemen_new][por_elemen_new_1] = masiv[j];
        kol_elemen_v_podmas += 1;
        pod_masivy[por_elemen_new][1000] = kol_elemen_v_podmas;
    }// dla uczeta nylia pri koniec
    pod_masivy[por_elemen_new][1000] = kol_elemen_v_podmas; // dla srav maks kolic elem v masive

    int max_ilosc_elem = 0;
    for (int m = 0; m < 500; m++) {
        if (pod_masivy[m][1000] > max_ilosc_elem) {
            max_ilosc_elem = pod_masivy[m][1000];
        }

    }
    if (max_ilosc_elem == 1 || max_ilosc_elem == 0)
    {
        printf("0\n0\n");
        return 0;
    }
    int ilosc_ciag_z_max = 0;
    for (int m1 = 0; m1 < 500; m1++)
    {
        if (pod_masivy[m1][1000] == max_ilosc_elem)
        {
            ilosc_ciag_z_max += 1;
        }
    }
    printf("%d\n", max_ilosc_elem);
    printf("%d\n", ilosc_ciag_z_max);
    for(int g = 0; g < 500; g++)
    {
        if (pod_masivy[g][1000] == max_ilosc_elem){
            printf("%d - ", pod_masivy[g][1001]);
            for (int h = 0; h < 1000; h++) {
                if (pod_masivy[g][h] != 0 && h < 1000) {
                    printf("%d ", pod_masivy[g][h]);
                } else if (pod_masivy[g][h] == 0) {
                    printf("\n");
                    break;
                }
            }
        }
    }

    return 0;
}
