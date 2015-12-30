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

int i = 0;

int main(void) {
	int fifo1 = 0;
	int fifo2 = 0;
	pid_t pid;
	char bufparent[100] = {};
	char bufchild[100] = {};
	char holder1[100] = {};
	char holder2[100] = {};
	int i = 0;

	fifo1 = open("fifo1", O_RDONLY);
	fifo2 = open("fifo2", O_RDONLY);

	if(fifo1 == -1 && fifo2 == -1){
		mkfifo("fifo1", S_IRUSR | S_IWUSR);
		fifo1 = open("fifo1", O_RDWR);

		mkfifo("fifo2", S_IRUSR | S_IWUSR);
		fifo2 = open("fifo2", O_RDWR);
	}

	pid = fork();

	if (pid > 0) {

		while (strcmp(bufparent, "exit") && strcmp(holder1, "exit")) {
			fgets(bufparent, sizeof(bufparent), stdin);
			bufparent[strlen(bufparent) - 1] = 0;
			write(fifo1, bufparent, sizeof(bufparent));
			printf("(%d)Sender: Sent %s\n", getpid(), bufparent);


			read(fifo2, holder1, sizeof(holder1));
			printf("(%d)Sender: Received %s\n", getpid(), holder1);
		}

		close(fifo1);
		close(fifo2);

	} else if (pid == 0) {

		while (strcmp(bufchild, "exit") && strcmp(holder2, "exit")) {
			read(fifo1, holder2, sizeof(holder2));
			printf("(%d)Receiver: Received %s\n", getpid(), holder2);


			fgets(bufchild, sizeof(bufchild), stdin);
			bufchild[strlen(bufchild) - 1] = 0;
			write(fifo2, bufchild, sizeof(bufchild));
			printf("(%d)Receiver: Sent %s\n", getpid(), bufchild);
		}

		close(fifo1);
		close(fifo2);
		exit(0);
	} else {
		printf("Error : %d", errno);
		perror(NULL);
	}

	unlink("fifo1");
	unlink("fifo2");

	exit(0);
}


