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
#include <sys/signal.h>
#include <errno.h>

pid_t childpid;
int i = 0;
time_t t0;

void kill_child(int signum) {

	printf("Tries: %d, time elapsed: %.2f\n", i - 1, difftime(time(NULL), t0));
	kill(childpid, SIGKILL);
}

int main(void) {
	char super[] = "Supercalifragilisticexpialidocious";
	char input[100] = {};
	
	t0 = time(NULL);

	childpid = fork();

	if (childpid > 0) {

	} else if (childpid == 0) {
		signal(SIGALRM, kill_child);
		
		alarm(30);

		printf("Please type in '%s'.\n", super);

		while (strcmp(input, super)) {
			i++;
			fgets(input, sizeof(input), stdin);
			input[strlen(input) - 1] = 0;
			
			if(strcmp(input, super)){
				puts("Please try again.");
			}


		}

		alarm(0);
	}

	wait(&childpid);

	printf("Tries: %d, time elapsed: %.2f\n", i, difftime(time(NULL), t0));

	kill(childpid, SIGKILL);

	exit(0);
}


