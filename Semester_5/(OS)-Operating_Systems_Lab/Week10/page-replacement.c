#include <stdio.h>
#include <stdlib.h>

#define FRAME_SIZE 3
#define PAGE_REF_STRING_SIZE 10

int page_ref[PAGE_REF_STRING_SIZE] = {2, 3, 2, 1, 5, 2, 4, 5, 3, 2};
int frames[FRAME_SIZE], fifo[FRAME_SIZE], lru[FRAME_SIZE], hits[3], page_faults;

int findOptimalVictim(int start) {
    int victim = -1, farthest = -1;
    for (int i = 0; i < FRAME_SIZE; i++) {
        for (int j = start; j < PAGE_REF_STRING_SIZE; j++) {
            if (frames[i] == page_ref[j] && j > farthest) {
                farthest = j;
                victim = i;
            }
        }
        if (victim == -1) return i;
    }
    return victim;
}

int findLruVictim(int used[]) {
    int victim = 0, min_used = used[0];
    for (int i = 1; i < FRAME_SIZE; i++) {
        if (used[i] < min_used) {
            min_used = used[i];
            victim = i;
        }
    }
    return victim;
}

int main() {
    for (int i = 0; i < FRAME_SIZE; i++)
        frames[i] = fifo[i] = lru[i] = -1;
    
    for (int i = 0; i < PAGE_REF_STRING_SIZE; i++) {
        int page = page_ref[i], found = 0;
        for (int j = 0; j < FRAME_SIZE; j++) {
            if (frames[j] == page) {
                hits[0]++;
                found = 1;
                lru[j] = i;
                break;
            }
        }
        if (!found) {
            page_faults++;
            if (i < FRAME_SIZE)
                fifo[i] = lru[i] = frames[i] = page;
            else {
                int v_fifo = fifo[0], v_lru = lru[0];
                for (int j = 1; j < FRAME_SIZE; j++) {
                    if (fifo[j] == -1) {
                        v_fifo = j;
                        break;
                    }
                    if (lru[j] < lru[v_lru])
                        v_lru = j;
                }
                frames[v_fifo] = frames[v_lru] = page;
                fifo[i % FRAME_SIZE] = lru[v_lru] = page;
            }
        }
    }
    hits[1] = hits[2] = PAGE_REF_STRING_SIZE - page_faults - hits[0];
    printf("FIFO: Page Faults = %d, Page Hits = %d\n", page_faults, hits[0]);
    printf("Optimal: Page Faults = %d, Page Hits = %d\n", page_faults, hits[1]);
    printf("LRU: Page Faults = %d, Page Hits = %d\n", page_faults, hits[2]);
    return 0;
}
