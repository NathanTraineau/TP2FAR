#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
	pid_t pid;
	int i = 0;
	int descr[2];
	int descr2[2];
	int somme = 0;
	pipe(descr);
	pipe(descr2);
	pid = fork();

	if (pid != 0){
		printf("Je suis le père");
		close(descr[0]);
		close(descr2[1]);
		while (i<5 ){

			write (descr[1], &i, sizeof(int));
			printf("%d", i);
			i=i+1;
		}
		//while( wait(0) != -1){}
		int res;
		while(read( descr2[0], &res, sizeof(int)) != 0){}
		printf("La somme est : %d", res);

	} 
	else{
		int nb;
		close(descr2[0]);
		close(descr[1]);
		while(read( descr[0], &nb, sizeof(int)) != 0){
			somme = somme + nb;
		}
		write (descr2[1], &somme, sizeof(int));
	}
	return EXIT_SUCCESS;
}

