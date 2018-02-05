#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void){
	pid_t pid;
	
	int descr[2];
	pipe(descr);
	pid = fork();
	int booleen = 0;
	int moy;
	int entier ;
	if (pid == 0 ){
		while(booleen == 0 ){
			printf("Entrez un entier");
			scanf("%d", &entier);
			write(descr[1], &entier, sizeof(int));
			printf("Continuer ? 0 : oui, 1 : non");
			scanf("%d", &booleen);
	}
	
	else {
		close(descr[1]);
		int somme = 0;
		int msg ;
		int cpt = 0;

		while (wait (0) != -1){}
		while(read(descr[0], &msg , sizeof(int)) != 0){
			somme = somme + msg;
			cpt+=1;
		}
		int moy = somme / cpt;
		printf("La moyenne est %d", moy);
	}
}
		



