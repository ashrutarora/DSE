#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t parent_pid = getpid();

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {
        // Child process
        pid_t child_pid = getpid();
        printf("Child process: My PID is %d\n", child_pid);
        printf("Child process: My parent's PID before parent death is %d\n", getppid());

        // Sleep for a while to delay termination
        sleep(5);

        printf("Child process: My parent's PID after parent death is %d\n", getppid());
        printf("Child process: I am an orphan process now.\n");

        exit(0);
    } else {
        // Parent process
        printf("Parent process: My PID is %d\n", parent_pid);

        // Intentionally exit without waiting for the child
        exit(0);
    }

    return 0;
}

