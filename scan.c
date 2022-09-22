//elevator algo
#include<stdio.h>
#include<stdlib.h>
int main()
{
 int RQ[100],i,j,n,TotalHeadMovement=0,initial,size,move;
 printf("Enter the number of Requests\n");
 scanf("%d",&n);
 printf("Enter the Requests sequence\n");
 for(i=0;i<n;i++)
 scanf("%d",&RQ[i]);
 printf("Enter initial head position\n");
 scanf("%d",&initial);
 printf("Enter total disk size\n");
 scanf("%d",&size);
 printf("Enter the head movement direction for high 1 and for low 0\n");
 scanf("%d",&move);
 
//high1 to move the disk arm towards larger value
//low0 to move the disk arm towards smaller value

 // logic for Scan disk scheduling

 /*logic for sort the request array */
 for(i=0;i<n;i++)
 {
 for(j=0;j<n-i-1;j++)
 {
 if(RQ[j]>RQ[j+1])
 {
 int temp;
 temp=RQ[j];
 RQ[j]=RQ[j+1];
 RQ[j+1]=temp;
 }
 }
 }
 //to calculate the index of the initial val
 int index;
 for(i=0;i<n;i++)
 {
 if(initial<RQ[i])
 {
 index=i;
 break;
 }
 }

 // if movement is towards high value
 if(move==1)
 {
 //for(i=index;i<n;i++) //from initial to max
//{
 //TotalHeadMovement=TotalHeadMovement+abs(RQ[i]-initial);
 //initial=RQ[i];
 //}
 TotalHeadMovement += size-1-initial;
 // last movement for max size
 //TotalHeadMovement=TotalHeadMovement+abs(size-RQ[i-1]-1);
 //initial = size-1;
 //for(i=index-1;i>=0;i--)
 //{
 printf("total: %d",TotalHeadMovement);
 //TotalHeadMovement=TotalHeadMovement+abs(RQ[i]-initial);
 //initial=RQ[i];
 TotalHeadMovement += (size-1- RQ[0]);
 printf("total: %d",TotalHeadMovement);
 
 }
 // if movement is towards low value
 else
 {
 for(i=index-1;i>=0;i--)
 {
 TotalHeadMovement=TotalHeadMovement+abs(RQ[i]-initial);
 initial=RQ[i];
 }
 // last movement for min size
 TotalHeadMovement=TotalHeadMovement+abs(RQ[i+1]-0);
 initial =0;
 for(i=index;i<n;i++)
 {
 TotalHeadMovement=TotalHeadMovement+abs(RQ[i]-initial);
 initial=RQ[i];

 }
 }

 printf("Total head movement is %d",TotalHeadMovement);
 return 0;
}
