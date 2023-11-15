#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	
	pid_t parent_pid = getpid();
	printf("Parent process ID = %d\n", parent_pid);
	
	pid_t pid = fork();

	if(pid < 0) {
		perror("Fork Failed");
		exit(1);
	}
	
	else if(pid == 0){
		pid_t child_pid = getpid();
		printf("Child PID = %d\n", child_pid);
		printf("Parent PID in child = %d\n", getppid());

		exit(0);
	}
	else{
		 printf("Parent PID  = %d\n", parent_pid);
		 printf("Child PID in parent = %d\n", pid);

		int status;
		wait(&status);
		printf("Parent process: Child has completed.\n");
	}

	return 0;
}