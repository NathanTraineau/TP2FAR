#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(void){
	pid_t pid;
	int i = 0;
	int nb [ 100];
	int descr[2];
	int somme;
	pipe(descr);
	pid = fork();
	if (pid != 0){
		while (i<5 ){
			nb = i;
			write (descr[1], &nb, sizeof(int));
			printf("%s", &nb);
			i=i+1;
		}
	} 
	else if (pid == 0){
				while( read( descr[0], &nb, sizeof(int))){
				somme = somme + nb;
			}
				write (descr[1], &somme, sizeof(int));
	}	
	else { 
		while (wait (0) != -1){};
		if (pid != 0){
			while( read( descr[0], &nb, sizeof(int))){ #Ca repars de là ou on a pas lu ou au tout début ?
				&somme = &nb ; 
			printf("La somme est = %d \n", somme)
			}
		}
	}
}