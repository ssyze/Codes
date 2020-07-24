#include <bits/stdc++.h>
using namespace std;
int a[10];
int main()
{
    while (scanf("%d", &a[0]) != EOF)
    {
        bool first = 0;
        int cnt0 = 0, ep = 8;
        for (int i = 1; i < 9; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i < 9; i++)
            if (a[i] == 0)
                cnt0++;
        if (cnt0 == 9)
        {
            puts("0");
            continue;
        }
        if (a[0] != 0)
        {
            if (a[0] == 1)
                printf("x^%d", ep);
            else if (a[0] == -1)
                printf("-x^%d", ep);
            else
                printf("%dx^%d", a[0], ep);
            first = 1;
        }
        ep--;
        for (int i = 1; i < 7; i++)
        {
            if (a[i] == 0)
            {
                ep--;
                continue;
            }
            else
            {
                if (!first)
                {
                    if (a[i] < 0)
                        if (a[i] == -1)
                            printf("-x^%d", ep--);
                        else
                            printf("-%dx^%d", -a[i], ep--);
                    else if (a[i] == 1)
                        printf("x^%d", ep--);
                    else
                        printf("%dx^%d", a[i], ep--);
                    first = 1;
                }
                else
                {
                    if (a[i] < 0)
                        if (a[i] == -1)
                            printf(" - x^%d", ep--);
                        else
                            printf(" - %dx^%d", -a[i], ep--);
                    else if (a[i] == 1)
                        printf(" + x^%d", ep--);
                    else
                        printf(" + %dx^%d", a[i], ep--);
                }
            }
        }
        if (a[7] == 0)
            ;
        else
        {
            if (!first)
            {
                if (a[7] < 0)
                    if (a[7] == -1)
                        printf("-x");
                    else
                        printf("-%dx", -a[7]);
                else if (a[7] == 1)
                    printf("x");
                else
                    printf("%dx", a[7]);
                first = 1;
            }
            else
            {
                if (a[7] < 0)
                    if (a[7] == -1)
                        printf(" - x");
                    else
                        printf(" - %dx", -a[7]);
                else if (a[7] == 1)
                    printf(" + x", ep--);
                else
                    printf(" + %dx", a[7]);
            }
        }

        if (a[8] == 0)
            printf("\n");
        else
        {
            if (!first)
            {
                if (a[8] < 0)
                    printf("%d\n", a[8]);
                else
                    printf("%d\n", a[8]);
            }
            else
            {
                if (a[8] < 0)
                    printf(" - %d\n", -a[8]);
                else
                    printf(" + %d\n", a[8]);
            }
        }
    }
}

/*
0 0 1 2 3 4 5 6 7
0 0 0 0 0 0 -55 5 0
0 0 0 0 0 0 0 0 0
1000 1000 0 3 6 -55 -100 3 0
-1 0 1 0 0 0 6 0 -1
0 0 0 6 -1 2 0 0 0
1000 205 320 56 54 -3 0 0 0
*/