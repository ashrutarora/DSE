#include <stdio.h>

#define MAX_PROCESSES 100

int main()
{
    int n, i, time_quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int burst_time[MAX_PROCESSES];
    int remaining_time[MAX_PROCESSES];

    printf("Enter time quantum: ");
    scanf("%d", &time_quantum);

    // Initialize burst times and remaining times
    for (i = 0; i < n; i++)
    {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
        remaining_time[i] = burst_time[i];
    }

    printf("\nGantt Chart:\n");

    int current_time = 0;
    while (1)
    {
        int done = 1; // Flag to check if all processes are done

        for (i = 0; i < n; i++)
        {
            if (remaining_time[i] > 0)
            {
                done = 0;
                int execute_time = (remaining_time[i] < time_quantum) ? remaining_time[i] : time_quantum;
                remaining_time[i] -= execute_time;
                current_time += execute_time;

                // Display process number
                printf("| P%d ", i + 1);
            }
        }

        if (done)
        {
            break; // All processes are done
        }
    }

    printf("|\n");

    return 0;
}


// #include <stdio.h>

// #define MAX_PROCESSES 100

// int main()
// {
//     int n, i, time_quantum;

//     printf("Enter the number of processes: ");
//     scanf("%d", &n);

//     int burst_time[MAX_PROCESSES];
//     int remaining_time[MAX_PROCESSES];
//     int waiting_time[MAX_PROCESSES] = {0}; // Initialize waiting time to 0

//     printf("Enter time quantum: ");
//     scanf("%d", &time_quantum);

//     // Initialize burst times and remaining times
//     for (i = 0; i < n; i++)
//     {
//         printf("Enter burst time for process %d: ", i + 1);
//         scanf("%d", &burst_time[i]);
//         remaining_time[i] = burst_time[i];
//     }

//     printf("\nGantt Chart:\n");

//     int current_time = 0;
//     while (1)
//     {
//         int done = 1; // Flag to check if all processes are done

//         for (i = 0; i < n; i++)
//         {
//             if (remaining_time[i] > 0)
//             {
//                 done = 0;
//                 int execute_time = (remaining_time[i] < time_quantum) ? remaining_time[i] : time_quantum;
//                 remaining_time[i] -= execute_time;
//                 current_time += execute_time;

//                 // Display process number
//                 printf("| P%d ", i + 1);

//                 // Update waiting time for other processes
//                 for (int j = 0; j < n; j++)
//                 {
//                     if (j != i && remaining_time[j] > 0)
//                     {
//                         waiting_time[j] += execute_time;
//                     }
//                 }
//             }
//         }

//         if (done)
//         {
//             break; // All processes are done
//         }
//     }

//     printf("|\n");

//     // Calculate Turnaround Time and Average Waiting Time
//     double total_waiting_time = 0;
//     double total_turnaround_time = 0;

//     printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
//     for (i = 0; i < n; i++)
//     {
//         int turnaround_time = burst_time[i] + waiting_time[i];
//         total_waiting_time += waiting_time[i];
//         total_turnaround_time += turnaround_time;

//         printf("P%d\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i], waiting_time[i], turnaround_time);
//     }

//     double average_waiting_time = total_waiting_time / n;
//     double average_turnaround_time = total_turnaround_time / n;

//     printf("\nAverage Waiting Time: %.2lf\n", average_waiting_time);
//     printf("Average Turnaround Time: %.2lf\n", average_turnaround_time);

//     return 0;
// }

