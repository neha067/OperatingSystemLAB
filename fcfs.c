//disk scheduling algo #1
#include<stdio.h>
#include<stdlib.h>
int main()
{
 int RQ[100],i,n,TotalHeadMovement=0,initial;
 printf("Enter the number of Requests\n");
 scanf("%d",&n);
 printf("Enter the Requests sequence\n");
 for(i=0;i<n;i++)
 scanf("%d",&RQ[i]);
 printf("Enter initial head position\n");
 scanf("%d",&initial);

 // logic for FCFS disk scheduling

 for(i=0;i<n;i++)
 {
 TotalHeadMovement=TotalHeadMovement+abs(RQ[i]-initial);
 initial=RQ[i];
 }
//total cost/time:
 printf("Total head moment is %d",TotalHeadMovement);
 return 0;

}
