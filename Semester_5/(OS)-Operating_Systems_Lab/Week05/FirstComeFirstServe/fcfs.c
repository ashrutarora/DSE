#include <stdio.h>

#define MAX 30

void calculateWaitingTime(int n, int bt[MAX], int wt[MAX]) {
    wt[0] = 0;

    for (int i = 1; i < n; i++) {
        wt[i] = 0;

        // Waiting Time Calculation
        for (int j = 0; j < i; j++) {
            wt[i] += bt[j];
        }
    }
}

void calculateTurnaroundTime(int n, int bt[MAX], int wt[MAX], int tat[MAX]) {
    for (int i = 0; i < n; i++) {
        // Turnaround Time Calculation
        tat[i] = wt[i] + bt[i];
    }
}

void displayProcessTable(int n, int bt[MAX], int wt[MAX], int tat[MAX]) {
    printf("Process-ID\t Burst-Time\t Waiting-Time\t Turn-Around-Time\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t\t %d\t\t%d\t\t %d\n", i + 1, bt[i], wt[i], tat[i]);
    }
}

void displayGanttChart(int n, int tat[MAX]) {
    printf("\nGantt Chart:\n");
    printf("\t");
    for (int i = 0; i < n; i++) {
        printf("P%d \t", i + 1);
    }
    printf("\n");
    printf("0\t");

    for (int i = 0; i < n; i++) {
        printf("%d\t", tat[i]);
    }
}

int main() {
    int n, bt[MAX], wt[MAX], tat[MAX];
    float awt = 0, atat = 0;

    printf("Enter the Number of Processes: ");
    scanf("%d", &n);

    printf("Enter the Burst Time for %d processes: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }

    // Calculate waiting times and turnaround times
    calculateWaitingTime(n, bt, wt);
    calculateTurnaroundTime(n, bt, wt, tat);

    // Display the process table and Gantt chart
    displayProcessTable(n, bt, wt, tat);
    displayGanttChart(n, tat);

    for (int i = 0; i < n; i++) {
        awt += wt[i];
        atat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", awt / n);
    printf("\nAverage Turn Around Time = %.2f", atat / n);

    return 0;
}
