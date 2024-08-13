#include <stdio.h>
#include <pthread.h>

#define MAX_FIB_NUM 100

unsigned long long fib[MAX_FIB_NUM];

void *generateFib(void *arg) {
    int n = *((int *)arg);
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    pthread_exit(0);
}

int main(int argc, char *argv[]) {
    int n;

    if (argc != 2) {
        printf("Usage: %s <number_of_Fibonacci_numbers>\n", argv[0]);
        return 1;
    }

    n = atoi(argv[1]);
    if (n <= 0 || n > MAX_FIB_NUM) {
        printf("Please enter a positive number between 1 and %d.\n", MAX_FIB_NUM);
        return 1;
    }

    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    pthread_create(&tid, &attr, generateFib, &n);
    pthread_join(tid, NULL);

    printf("Fibonacci Series for %d numbers: ", n);
    for (int i = 0; i < n; i++) {
        printf("%llu ", fib[i]);
    }
    printf("\n");

    return 0;
}
