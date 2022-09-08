//Dining Philosopher's Problem
/* A resource sharing problem
*/
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

sem_t room; //counting semaphore as 1 dining can accommodate 4 philo. aka
//multiple instances
sem_t chopstick[5];
//chopstick as binary semaphore since for every chopstick we have one instance of it
void * philosopher(void *);
void eat(int);
int main()
{
	int i,a[5];
	pthread_t tid[5]; //these threads refer to the 5 philo :3
	//threads bcz we want them to execute simultaneously,many can eat at same time
	
	sem_init(&room,0,4); //function sem_init to initialize the semaphore
	
	/*  parameters explanation:-
	room: pointer to declared semaphore
	0: pshared,if 0 semaphore is shared b/w threads, else b/w processes
	in our case its b/w threads
	4:  value with which semaphore is initialized */

	for(i=0;i<5;i++)
		sem_init(&chopstick[i],0,1);

	for(i=0;i<5;i++)
	{
		a[i]=i;
		pthread_create(&tid[i],NULL,philosopher,(void *)&a[i]);
		
		/* We are calling the function philosopher() from pthread_create and passing it the address of an integer variable which refers to the philosopher number.*/
	}
	for(i=0;i<5;i++)
		pthread_join(tid[i],NULL);
}
40580894246
void * philosopher(void * num)
{
	int phil=*(int *)num;

	sem_wait(&room); 
	//sem_wait function checks if resource is availabe, if yes 
	//then allocates and semaphore is locked
	
	printf("\nPhilosopher %d has entered room",phil);
	sem_wait(&chopstick[phil]);
	sem_wait(&chopstick[(phil+1)%5]);

	eat(phil);
	sleep(2);
	printf("\nPhilosopher %d has finished eating",phil);

	sem_post(&chopstick[(phil+1)%5]); //sem_post function frees the resource
	sem_post(&chopstick[phil]);
	sem_post(&room);
}

void eat(int phil)
{
	printf("\nPhilosopher %d is eating",phil);
} 

