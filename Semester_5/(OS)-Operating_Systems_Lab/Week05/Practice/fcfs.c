#include <stdio.h>
#define max 30

int main()
{

    int n, p[max], bt[max], wt[max], tat[max];
    float awt = 0, atat = 0;

    printf("Enter the number of processes: \n");
    scanf("%d", &n);

    printf("Enter the Process Number for %d Processes: ", n);
    for (int i = 0; i < n; i++)
    {

        scanf("%d", &p[i]);
    }

    printf("Enter the Burst Time for %d Processes: ", n);
    for (int i = 0; i < n; i++)
    {

        scanf("%d", &bt[i]);
    }

    // Sorting as per shortest BT

    // for (int i = 0; i < n - 1; i++)
    // {
    //     for (int j = 0; j < n - i - 1; j++)
    //     {
    //         if (bt[j] > bt[j + 1])
    //         {
    //             int temp = bt[j];
    //             bt[j] = bt[j + 1];
    //             bt[j + 1] = temp;

    //             temp = p[j];
    //             p[j] = p[j + 1];
    //             p[j + 1] = temp;
    //         }
    //     }
    // }

    // Output Table
    printf("PID \t BT \t WT \t TAT \n");

    // Calculations
    for (int i = 0; i < n; i++)
    {

        wt[i] = 0;
        tat[i] = 0;

        // WT
        for (int j = 0; j < i; j++)
        {

            wt[i] += bt[j];
        }

        // TAT
        tat[i] = wt[i] + bt[i];

        // AWT ATAT
        awt = awt + wt[i];
        atat = atat + tat[i];

        printf("%d\t %d\t %d\t %d\n", p[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", awt / n);
    printf("\nAverage Turn Around Time = %.2f", atat / n);

    // Gantt chart

    printf("\n\n Gantt CHart \n\n");
    printf("\t");

    for (int i = 0; i < n; i++)
    {
        printf("P%d \t", p[i]);
    }

    printf("\n");
    printf("0\t");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t", tat[i]);
    }

    return 0;
}