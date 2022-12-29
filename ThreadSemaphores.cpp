#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int a1, a2, b1, b2, c1, c2, x, y, z, w;
pthread_t thread_id[3];
sem_t *sem[7];  //Named semaphore
/*sem[0] -> a2
sem[1] -> b1
sem[2] -> c1
sem[3] -> c2
sem[4] -> x
sem[5] -> y
sem[6] -> z*/

void* t1(){
	a1 = 10;
	a2 = 11;
	sem_post(sem[0]);
	sem_wait(sem[2]);
	y = a1 + c1;
	sem_post(sem[5]);
	sem_wait(sem[4]);
	printf("x = %d\n", x);
}

void* t2(){
	b1 = 20;
	sem_post(sem[1]);
	b2 = 21;
	sem_wait(sem[3]);
	w = b2 + c2;
	sem_wait(sem[5]);
	sem_wait(sem[6]);
	x = z - y + w;
	sem_post(sem[4]);
}

void* t3(){
	c1 = 30;
	sem_post(sem[2]);
	c2 = 31;
	sem_post(sem[3]);
	sem_wait(sem[0]);
    sem_wait(sem[1]);
	z = a2 + b1;
    sem_post(sem[6]);
}

int main(){
	int i = 0;
    
    for(i=0; i<7; i++){
    	sem[i] = sem_open("/SEM_NAME"+i, O_CREAT, 0644, 0);
	}
    
    if(pthread_create(&thread_id[0], NULL, t1, NULL)<0){
    	printf("Thread failed\n");
	}
	if(pthread_create(&thread_id[1], NULL, t2, NULL)<0){
    	printf("Thread failed\n");
	}
	
    if(pthread_create(&thread_id[2], NULL, t3, NULL)<0){
    	printf("Thread failed\n");
	}
	
    pthread_join(thread_id[0], NULL);
    pthread_join(thread_id[1], NULL);
    pthread_join(thread_id[2], NULL);
	
	for(i=0; i<7; i++){
    	sem_unlink("/SEM_NAME"+i);
	}
	
	return 0;
}
