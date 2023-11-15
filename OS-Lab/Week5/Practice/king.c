#include <stdio.h>
#define max 30

int main()
{

    int n, p[max], bt[max], wt[max], tat[max];
    float awt = 0, atat = 0;

    printf("Enter the number of processes : \n");
    scanf("%d", &n);

    printf("Enter the Process Number for %d processes: \n", n);
    for (int i = 0; i < n; i++)
    {

        scanf("%d", &p[i]);
    }

    printf("Enter the Burst time for %d processes: \n", n);
    for (int i = 0; i < n; i++)
    {

        scanf("%d", &bt[i]);
    }

    // Sorting as per BT

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (bt[j] > bt[j + 1])
            {

                int temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    printf("\nPID \t BT \t WT \t TAT \n");

    for (int i = 0; i < n; i++)
    {

        wt[i] = 0;
        tat[i] = 0;

        for (int j = 0; j < i; j++)
        {

            wt[i] += bt[j];
        }

        tat[i] = wt[i] + bt[i];

        awt = awt + wt[i];
        atat = atat + tat[i];

        printf("%d \t %d \t %d \t %d \n", p[i], bt[i], wt[i], tat[i]);
    }

    printf("Avg WT = %.2f\n", awt / n);
    printf("Avg TAT = %.2f\n", atat / n);

    printf("\n\nGantt Chart\n\n");
    printf("\t");

    for (int i = 0; i < n; i++)
    {

        printf("P%d \t", i + 1);
    }

    printf("\n");
    printf("0 \t");

    for (int i = 0; i < n; i++)
    {

        printf("%d \t", tat[i]);
    }

    return 0;
}