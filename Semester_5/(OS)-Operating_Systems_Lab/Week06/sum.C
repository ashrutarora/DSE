#include <stdio.h>
#include <pthread.h>

#define MAX_VALUES 100

int values[MAX_VALUES];
int num_values = 0;
int sum = 0;

void *calculateSum(void *arg)
{
    int localSum = 0;

    for (int i = 0; i < num_values; i++)
    {
        localSum += values[i];
    }

    sum = localSum;
    pthread_exit(NULL);
}

int main()
{
    pthread_t thread;

    printf("Enter non-negative integers (enter a negative number to stop):\n");

    while (1)
    {
        int value;
        scanf("%d", &value);

        if (value < 0)
        {
            break;
        }

        if (num_values < MAX_VALUES)
        {
            values[num_values] = value;
            num_values++;
        }
        else
        {
            printf("Max number of values reached. Calculation will be performed with the available values.\n");
            break;
        }
    }

    if (pthread_create(&thread, NULL, calculateSum, NULL))
    {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    pthread_join(thread, NULL);

    printf("Sum of non-negative integers: %d\n", sum);

    return 0;
}
