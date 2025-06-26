#include <stdio.h>

int main() {
    int day, month, year;
    printf("Podaj date (w formacie dd-mm-yyyy):");
    if(scanf("%02d-%02d-%04d", &day, &month, &year) == 3)
    {
        if (day<=0 || month<=0 || year <= 0 || month > 12 || (month == 4 && day >30) || (month == 6 && day >30))
        {printf("Incorrect");}
        else if ((month == 2 && day >28 && year%4 != 0) || (month == 11 && day > 30) || (month == 9 && day > 30))
            printf("Incorrect");
        else if (month == 2 && day >28 && year%4 == 0 && year%100 == 0 && year%400 == 0 )
            printf("Correct");
        else if (month == 2 && day >28 && year%4 == 0 && year%100 == 0 )
            printf("Incorrect");
        else printf("Correct");
    }

    else{
        printf("Incorrect input");
        return 1;
    }
    return 0;
}
