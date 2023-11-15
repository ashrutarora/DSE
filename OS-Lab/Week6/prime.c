#include <stdio.h>
#include <pthread.h>

// Function to check if a number is prime
int is_prime(int n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
}

// Thread function to find primes within a range
void* find_primes(void* arg) {

    int* args = (int*)arg;
    int start = args[0];
    int end = args[1];

    for (int i = start; i <= end; i++) {
        
        if (is_prime(i)) {
            printf("%d is prime.\n", i);
        }
    }

    pthread_exit(NULL);
}

int main() {
    int start = 2; // Starting number
    int end = 100; // Ending number

    pthread_t thread;
    int args[] = {start, end};
    
    pthread_create(&thread, NULL, find_primes, (void*)args);
    pthread_join(thread, NULL);

    return 0;
}
