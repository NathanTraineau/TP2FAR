#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


void traitement(){
	printf("L'entier est négatif !");
}

int main(void){
	pid_t pid;
	int descr[2];
	pipe(descr);
	pid = fork();
	int entier;
	if (pid != 0 ){
		while(1){
		printf("Entrez un entier");
		scanf("%d", &entier);
		write(descr[1], &entier, sizeof(int));
		}
	}
	else{
		int res;
		while(read( descr[0], &res, sizeof(int)) != 0){}
		if(res<0){
			signal(SIGUSR1, traitement);
		}
	}
}
