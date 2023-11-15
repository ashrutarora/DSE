#include <stdio.h>
#define max 30

int main() {
    int n, p[max], priority[max], bt[max], wt[max], tat[max];
    float awt = 0, atat = 0;

    printf("Enter the Number of Processes: ");
    scanf("%d", &n);

    printf("Enter the Process Numbers:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &p[i]);
    }

    printf("Enter the Priorities:\n");
    for (int i = 0; i < n; i++) {
        printf("Priority for Process %d: ", i + 1);
        scanf("%d", &priority[i]);
    }

    printf("Enter the Burst Times:\n");
    for (int i = 0; i < n; i++) {
        printf("Burst Time for Process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Sort the processes based on priority (ascending order)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (priority[j] > priority[j + 1]) {
                // Swap priority, process number, and burst time
                int temp = priority[j];
                priority[j] = priority[j + 1];
                priority[j + 1] = temp;

                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;

                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;
            }
        }
    }

    printf("Process-ID\t Priority\t Burst-Time\t Waiting-Time\t Turn-Around-Time\n");

    wt[0] = 0;
    tat[0] = bt[0];

    awt += wt[0];
    atat += tat[0];

    for (int i = 0; i < n; i++) {
        wt[i] = 0;
        tat[i] = 0;

        // Waiting Time Calculation
        for (int j = 0; j < i; j++) {
            wt[i] += bt[j];
        }

        // Turn-Around Time Calculation
        tat[i] = wt[i] + bt[i];

        // AWT, ATAT Calculation
        awt += wt[i];
        atat += tat[i];

        printf("%d\t\t %d\t\t%d\t\t %d\t\t %d\n", p[i], priority[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", awt / n);
    printf("\nAverage Turn-Around Time = %.2f\n", atat / n);

    // Gantt chart
    printf("\nGantt Chart:\n");
    printf("\t");
    for (int i = 0; i < n; i++) {
        printf("P%d\t", p[i]);
    }
    printf("\n");
    printf("0\t");
    for (int i = 0; i < n; i++) {
        printf("%d\t", tat[i]);
    }

    return 0;
}
