#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{

    int num;

    printf("How many integers in an array: \n");
    scanf("%d", &num);

    int arr[num];

    printf("Enter %d numbers: \n", num);
    for (int i = 0; i < num; i++)
    {

        scanf("%d", &arr[i]);
    }

    pid_t pid = fork();

    if (fork < 0)
    {

        printf("Fork failed");
        return 0;
    }
    else if (pid == 0)
    {

        printf("Inside child process\n");

        printf("Sorting in child process\n");

        // Sorting
        for (int i = 0; i < num - 1; i++)
        {
            for (int j = 0; j < num - i - 1; j++)
            {

                if (arr[j] > arr[j + 1])
                {

                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }

        printf("Displaying sorted in child process\n");

        // Displaying after sorting in child 
        for(int i = 0; i < num; i++){

            printf("%d \t", arr[i]);
        }
        printf("\n");

    }
    else{
        printf("Inside parent process\n");

        printf("Displaying unsorted in Parent process\n");
        // Displaying before sorting 

        for(int i = 0; i < num; i++){

            printf("%d \t", arr[i]);
        }
        printf("\n");

        wait(NULL);  
    }

    return 0;
}