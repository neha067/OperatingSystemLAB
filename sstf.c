#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int main()
{
 int RQ[100],i,n,TotalHeadMovement=0,initial,count=0;
 printf("Enter the number of Requests\n");
 scanf("%d",&n);
 printf("Enter the Requests sequence\n");
 for(i=0;i<n;i++)
 scanf("%d",&RQ[i]);
 printf("Enter initial head position\n");
 scanf("%d",&initial);

 // logic for sstf disk scheduling

 /* loop will execute until all process is completed*/
 while(count!=n)
 {
 int min=INT_MAX,d,index;
 for(i=0;i<n;i++) //to check the minimum seek time difference of all request...
 {
 d=abs(RQ[i]-initial);
 if(min>d)
 {
 min=d;
 index=i;
 }

 }
 TotalHeadMovement=TotalHeadMovement+min; //minimum one added to total
 initial=RQ[index]; //new initial is minimum...
 
 RQ[index]=INT_MAX; // 	To exclude in next iteration
 count++;
 }

 printf("Total head movement is %d",TotalHeadMovement);
 return 0;
}
