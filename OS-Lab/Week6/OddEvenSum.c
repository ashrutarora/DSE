#include <stdio.h>
#include <pthread.h>

// #define ARRAY_SIZE 10 

int ARRAY_SIZE = 0;
int input_array[];
int even_sum = 0, odd_sum = 0;

void *calculate_even_sum(void *arg)
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (input_array[i] % 2 == 0)
        {
            even_sum += input_array[i];
        }
    }
    pthread_exit(NULL);
}

void *calculate_odd_sum(void *arg)
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (input_array[i] % 2 != 0)
        {
            odd_sum += input_array[i];
        }
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t even_thread, odd_thread;

    printf("Enter number of integers in array: \n");
    scanf("%d", &ARRAY_SIZE);

    printf("Enter %d integers for the array:\n", ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        scanf("%d", &input_array[i]);
    }

    pthread_create(&even_thread, NULL, calculate_even_sum, NULL);
    pthread_create(&odd_thread, NULL, calculate_odd_sum, NULL);

    pthread_join(even_thread, NULL);
    pthread_join(odd_thread, NULL);

    printf("Sum of even numbers: %d\n", even_sum);
    printf("Sum of odd numbers: %d\n", odd_sum);

    return 0;
}
