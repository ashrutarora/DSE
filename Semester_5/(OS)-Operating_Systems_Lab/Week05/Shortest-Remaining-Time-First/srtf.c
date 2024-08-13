#include <stdio.h>
#define max 30

int main() {
    int n, p[max], bt[max], at[max], wt[max], tat[max], remaining[max];
    float awt = 0, atat = 0;

    printf("Enter the Number of Processes: ");
    scanf("%d", &n);

    printf("Enter the Process Number for %d processes: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    printf("Enter the Arrival Time for %d processes: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }

    printf("Enter the Burst Time for %d processes: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        remaining[i] = bt[i];
    }

    int time = 0, completed = 0;

    printf("\nGantt Chart:\n");

    while (completed != n) {
        int shortest = -1;
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && remaining[i] > 0) {
                if (shortest == -1 || remaining[i] < remaining[shortest]) {
                    shortest = i;
                }
            }
        }

        if (shortest == -1) {
            // No process is ready to run, increment time
            printf(" ");
            time++;
        } else {
            // Process shortest for 1 time unit
            printf("P%d ", p[shortest]);
            time++;
            remaining[shortest]--;

            // If the process is completed
            if (remaining[shortest] == 0) {
                completed++;
                wt[shortest] = time - at[shortest] - bt[shortest];
                if (wt[shortest] < 0)
                    wt[shortest] = 0;
                tat[shortest] = bt[shortest] + wt[shortest];
                awt += wt[shortest];
                atat += tat[shortest];
            }
        }
    }

    printf("\n");

    // Print the time they have run for at the bottom
    time = 0;
    printf("%d ", time);
    for (int i = 0; i < n; i++) {
        time += bt[i];
        printf("%d ", time);
    }

    printf("\n");

    printf("\nProcess-ID\t Arrival-Time\t Burst-Time\t Waiting-Time\t Turn-Around-Time\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t\t %d\t\t %d\t\t %d\t\t %d\n", p[i], at[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %f", awt / n);
    printf("\nAverage Turn Around Time = %f", atat / n);

    return 0;
}
