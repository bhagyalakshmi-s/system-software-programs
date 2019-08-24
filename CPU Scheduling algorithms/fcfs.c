#include<stdio.h>
void  main()
{
	int p[10],at[10],bt[10],ct[10],tat[10],wt[10],n,i;
	float avgwt=0,avgtat=0;
	printf("enter the number of processes:\n");
	scanf("%d",&n);
	printf("enter the burst time:\n");
	for (i=0;i<n;i++)
		scanf("%d",&bt[i]);
	printf("enter the arrival time:\n");
	for (i=0;i<n;i++)
		scanf("%d",&at[i]);
	ct[0]=at[0]+bt[0];
	for (i=1;i<n;i++)
		ct[i]=ct[i-1]+bt[i];
	for (i=0;i<n;i++)
	{
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-bt[i];
		avgtat+=tat[i];
		avgwt+=wt[i];
	}
	printf("\n\n P \t AT \t BT \t CT \t TAT \t WT \n");
	for (i=0;i<n;i++)
	{
		printf("%d \t %d \t %d \t %d \t %d \t %d \n\n",i,at[i],bt[i],ct[i],tat[i],wt[i]);
	}
	printf("\naverage waiting time=%f",avgwt/n);
	printf("\naverage turn around time time=%f",avgtat/n);
}
