//implementing fcfs cpu scheduling

//given: n processes with their burst time...
// task : find avg waiting time and turn around time

#include<stdio.h>

//since arrival time is 0 same for all avg waiting time and tat will be same
void findwaiting(int process[], int n, int burst_time[],int wt[]){
	int i=1;
	for(i=1; i<n; i++)
		wt[i] = burst_time[i-1] + wt[i-1];
}	
void findtat(int tat[], int process[], int n, int burst_time[],int wt[]){
	int i=0;
	for(i=0; i<n; i++)
		tat[i] = burst_time[i] + wt[i];
}
void findavgtime(int process[], int n, int burst_time[]){
	int wt[n]; int tat[n];
	wt[0] = 0;
	findwaiting(process,n,burst_time,wt);
	findtat(tat,process,n,burst_time,wt);
	int avg= 0,sum,i;
	for(i=0; i<n; i++)
		sum += wt[i];
	
	printf("avg wt:	%d",sum/n);
	sum=0;
	for(i=0; i<n; i++)
		sum += tat[i];
	printf("avg tat:	%d",sum/n);
}


int main(){
	int process[] = {1,2,3};
	int n = sizeof process / sizeof process[0];
	
	
	int burst_time[] = {10,5,8};
	
	findavgtime(process,n,burst_time);
	
	return 0;
}


