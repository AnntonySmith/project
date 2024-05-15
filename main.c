#include "lr.h"

int main()
{

    int n=1, dop;
    printf("Anna Kabanova\nProjects");
    while(n!=0)
    {
        printf("\n\nChose a lab number 1-7 or 0 for EXIT: ");
        scanf("%i", &n);
        switch (n){
            case 1:
                lab1();
                break;
            case 2:
            printf("1 or 2: ");
            scanf("%i", &dop);
                if (dop == 1) lab2();
                else lab2dop();
                break;
            case 3:
            printf("1 or 2: ");
            scanf("%i", &dop);
                if (dop == 1) lab3();
                else lab3dop();
                break;
            case 4:
            printf("1 or 2: ");
            scanf("%i", &dop);
                if (dop == 1) lab4();
                else lab4dop();
                break;
            case 5:
            printf("1 or 2: ");
            scanf("%i", &dop);
                if (dop == 1) lab5();
                else lab5dop();
                break;
            case 6:
            printf("1 or 2: ");
            scanf("%i", &dop);
                if (dop == 1) lab6();
                else lab6dop();
                break;
            case 7:
                lab7();
                break;
            case 0:
                return 0;
            default:
                continue;
        }
    }
    return 0;
}