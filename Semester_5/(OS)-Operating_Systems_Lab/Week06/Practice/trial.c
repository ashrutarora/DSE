#include <stdio.h>
#include <pthread.h>

#define max 100

int values[max];
int num_values = 0;
int sum = 0;

void* calcSum(void *arg){

    int localSum = 0;

    for(int i = 0; i < num_values; i++){

        localSum += values[i];
    }

    sum = localSum;
    pthread_exit(0);
}

int main()
{

    pthread_t thread;

    printf("Enter non negative integers: \n");

    while(1){

        int value;
        scanf("%d", &value);

        if(value < 0)
            break;
        
        else if(value < max){
            values[num_values] = value;
            num_values++;
        }
        else{
            printf("Max values reached\n");
            break;
        }
    }

    pthread_create(&thread, NULL, calcSum, NULL);
    pthread_join(thread, NULL);


    printf("Sum of non negative integers = %d\n", sum);
    return 0;
}