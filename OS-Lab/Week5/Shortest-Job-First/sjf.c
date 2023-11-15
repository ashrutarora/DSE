#include <stdio.h>
#define max 30

int main()
{

    int n, temp, p[max], bt[max], wt[max], tat[max];
    float awt = 0, atat = 0;

    printf("Enter the Number of Processes: ");
    scanf("%d", &n);

    printf("Enter the Process Number for %d processes: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }

    printf("Enter the Burst Time for %d processes: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }

    // Sorting as per shortest BT

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n - i - 1; j++)
        {

            if (bt[j] > bt[j + 1])
            {

                temp = bt[j];
                 bt[j] = bt[j + 1];
                bt[j+1] = temp;

                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }

    printf("Process-ID\t Burst-Time\t Waiting-Time\t Turn-Around-Time\n");

    wt[0] = 0;
    tat[0] = bt[0];

    awt += wt[0];
    atat += tat[0];


    for (int i = 0; i < n; i++){

        wt[i] = 0;
        tat[i] = 0;

        // Waiting Time Calc
        for (int j = 0; j < i; j++)
        {
            wt[i] += bt[j];
        }

        // TAT calc
        tat[i] = wt[i] + bt[i];

        // AWT, ATAT calc
        awt = awt + wt[i];
        atat = atat + tat[i];

        printf("%d\t\t %d\t\t%d\t\t %d\n", p[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %f", awt / n);
    printf("\nAverage Turn Around Time = %f", atat / n);

    // Gantt chart

    printf("\n\nGantt Chart:\n");
    printf("\t");
    for (int i = 0; i < n; i++){

        printf("P%d \t", p[i]);
    }
    printf("\n");
    printf("0\t");

    for (int i = 0; i < n; i++){

        printf("%d\t", tat[i]);
    }

    return 0;
}