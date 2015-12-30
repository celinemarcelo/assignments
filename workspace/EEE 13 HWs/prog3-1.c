#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <errno.h>

int main(void) {
	pid_t pid;
	int input = 0;

	pid = fork();

	if (pid > 0) {
		sleep(5);
	} else if (!pid) {
		puts("Please give a number.");
		scanf("%d", &input);
		printf("Input: %d\n", input);
	} else {
		printf("Error %d", errno);
		perror(NULL);
	}

	kill(pid, SIGKILL);
	exit(0);
}