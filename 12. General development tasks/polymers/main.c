#include <stdio.h>
#include <string.h>

void zamena(char* symbol)
{
    if (*(symbol+2) == '\0' || *(symbol+1) == '\0')
    {
        *symbol = '\0';
        return;
    }
    if (*(symbol+3) == '\0')
    {
        *symbol = *(symbol+2);
        *(symbol+1) = '\0';
        return;
    }
    *symbol = *(symbol+2);
    *(symbol+1) = *(symbol+3);
    zamena(symbol+2);

}

int pol(char* original, char* massive, int spraw)
{
    if (((*(massive) < 'A' || *(massive) > 'Z') && (*(massive) < 'a' || *(massive) > 'z') ||
            (*(massive+1) < 'A' || *(massive+1) > 'Z') && (*(massive+1) < 'a' || *(massive+1) > 'z')))
    {
        if (*(massive+1) != '\0' && *(massive) != '\0')
            return 2;
    }
    if (*(massive) == *(massive+1) - ' ' || *(massive) - ' ' == *(massive+1))
    {
        zamena(massive);
        spraw++;

    }
    if (*(massive+1) == '\0' || *massive == '\0')
    {
        if (spraw == 0)
            return 0;
        else
        {
            return pol(original, original, 0);
        }

    }
    else
        return pol(original, massive+1, spraw);


}



int main() {
    char massive [1001] = {'\0'};
    printf("Podaj polimer:");
    scanf("%1000[^\n]", massive);
    int spraw = pol(massive, massive, 0);
    if (spraw == 2)
    {
        printf("Incorrect input data");
        return 2;
    }
    if (*massive == '\0')
    {
        printf("Nothing to show");

    }
    else
        printf("%s", massive);
    return 0;
}
