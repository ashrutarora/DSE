#include <stdio.h>
#include <stdlib.h>

#define max 30

int main() {
    int n;
    printf("Enter the Number of Processes: ");
    scanf("%d", &n);

    int process_number[max], burst_time[max], arrival_time[max], waiting_time[max], turnaround_time[max];
    int currentTime = 0;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    printf("Enter the Burst Time and Arrival Time for %d processes:\n", n);
    for (int i = 0; i < n; i++) {
        process_number[i] = i + 1; // Store process number
        printf("Process %d - Burst Time: ", i + 1);
        scanf("%d", &burst_time[i]);
        printf("Process %d - Arrival Time: ", i + 1);
        scanf("%d", &arrival_time[i]);
    }

    // Sort processes by arrival time and process number using Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arrival_time[j] > arrival_time[j + 1] || (arrival_time[j] == arrival_time[j + 1] && process_number[j] > process_number[j + 1])) {
                // Swap burst times, arrival times, and process numbers
                int temp = burst_time[j];
                burst_time[j] = burst_time[j + 1];
                burst_time[j + 1] = temp;

                temp = arrival_time[j];
                arrival_time[j] = arrival_time[j + 1];
                arrival_time[j + 1] = temp;

                temp = process_number[j];
                process_number[j] = process_number[j + 1];
                process_number[j + 1] = temp;
            }
        }
    }

    printf("\nProcess-ID\tBurst-Time\tArrival-Time\tWaiting-Time\tTurn-Around-Time\n");

    for (int i = 0; i < n; i++) {
        if (arrival_time[i] > currentTime) {
            // Idle time
            int idle_time = arrival_time[i] - currentTime;
            currentTime = arrival_time[i];
            total_waiting_time += idle_time; // Add idle time to total waiting time
        }

        // Calculate waiting time for the current process
        waiting_time[i] = currentTime - arrival_time[i];

        // Ensure waiting time is non-negative
        if (waiting_time[i] < 0) {
            waiting_time[i] = 0;
        }

        // Calculate turnaround time for the current process
        turnaround_time[i] = waiting_time[i] + burst_time[i];

        // Update total waiting time and total turnaround time
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];

        // Update current time
        currentTime += burst_time[i];

        // Print process details
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               process_number[i],
               burst_time[i],
               arrival_time[i],
               waiting_time[i],
               turnaround_time[i]);
    }

    float average_waiting_time = (float)total_waiting_time / n;
    float average_turnaround_time = (float)total_turnaround_time / n;

    printf("\nAverage Waiting Time = %.2f", average_waiting_time);
    printf("\nAverage Turnaround Time = %.2f\n", average_turnaround_time);

    return 0;
}
