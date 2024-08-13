#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    pid_t pid;

    // Get the parent process ID
    pid_t parent_pid = getpid();

    printf("Parent PID: %d\n", parent_pid);

    // Creating a fork
    pid = fork();

    if (pid < 0)
    {

        perror("Fork failed");
        exit(1);
    }
    else if (pid == 0)
    {
        // Child process
        printf("Inside the child process \n");
        pid_t child_pid = getpid();
        printf("Child PID: %d\n", child_pid);

        printf("Child process executing...\n");
        sleep(3);
        printf("Child process completed.\n");
        exit(0);
    }
    else
    {
        // Parent process
        printf("Inside the Parent process \n");
        printf("Parent PID: %d\n", parent_pid);
        printf("Parent process waiting for child to complete...\n");

        int status;
        wait(&status);
        
        printf("Parent process: Child has completed.\n");
    }

    return 0;
}
