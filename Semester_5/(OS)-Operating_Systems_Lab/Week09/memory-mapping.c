#include <stdio.h>

int main() {
    int memory[] = {100, 500, 200, 300, 600}; // Memory partitions
    int n = 5; // Number of memory partitions
    int processes[] = {212, 417, 112, 426}; // Processes to allocate
    int m = 4; // Number of processes

    int allocation[n];

    for (int i = 0; i < n; i++) {
        allocation[i] = -1; // Initialize all memory partitions as unallocated
    }

    // First-fit allocation
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (allocation[j] == -1 && memory[j] >= processes[i]) {
                allocation[j] = i;
                break;
            }
        }
    }

    printf("First-fit Allocation:\n");
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1) {
            printf("Process %d is allocated to Memory Partition %d (%dK)\n", processes[allocation[i]], i, memory[i]);
        } else {
            printf("Memory Partition %d (%dK) is not allocated\n", i, memory[i]);
        }
    }

    // Reset allocation array for Best-fit
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    // Best-fit allocation
    for (int i = 0; i < m; i++) {
        int bestFit = -1;
        for (int j = 0; j < n; j++) {
            if (allocation[j] == -1 && memory[j] >= processes[i]) {
                if (bestFit == -1 || memory[j] < memory[bestFit]) {
                    bestFit = j;
                }
            }
        }
        if (bestFit != -1) {
            allocation[bestFit] = i;
        }
    }

    printf("\nBest-fit Allocation:\n");
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1) {
            printf("Process %d is allocated to Memory Partition %d (%dK)\n", processes[allocation[i]], i, memory[i]);
        } else {
            printf("Memory Partition %d (%dK) is not allocated\n", i, memory[i]);
        }
    }

    // Reset allocation array for Worst-fit
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    // Worst-fit allocation
    for (int i = 0; i < m; i++) {
        int worstFit = -1;
        for (int j = 0; j < n; j++) {
            if (allocation[j] == -1 && memory[j] >= processes[i]) {
                if (worstFit == -1 || memory[j] > memory[worstFit]) {
                    worstFit = j;
                }
            }
        }
        if (worstFit != -1) {
            allocation[worstFit] = i;
        }
    }

    printf("\nWorst-fit Allocation:\n");
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1) {
            printf("Process %d is allocated to Memory Partition %d (%dK)\n", processes[allocation[i]], i, memory[i]);
        } else {
            printf("Memory Partition %d (%dK) is not allocated\n", i, memory[i]);
        }
    }

    return 0;
}
