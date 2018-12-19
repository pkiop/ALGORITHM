#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#define N 100


long int x = 3;



void fork11() {
	int i;
	int pid[N];
	int child_status;

	for (i = 0; i < N; ++i)
		if ((pid[i] = fork()) == 0)
			exit(100 + i);
	for (i = N - 1; i >= 0; i--) {
		int wpid = waitpid(pid[i], &child_status, 0);
		if (WIFEXITED(child_status))
			printf("child %d terminated with exit status %d\n",
				wpid, WEXITSTATUS(child_status));
		else
			printf("Child %d terminate abnormally\n", wpid);
	}
}

int main(int argc, char* argv[]) {
	fork11();
	return 0;
}