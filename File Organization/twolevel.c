#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct directory
{
	char dname[10],fname[10][10];
	int fcount;
}dir[10];
void main()
{
	int i,j,k,choice,dcount=0,flag=0;
	char dtemp[10],ftemp[10];
	while (choice != 6)
	{
		printf("\n1.CREATE DIRECTORY\n2.CREATE FILE\n3.DELETE FILE\n4.SEARCH FILE\n5.DISPLAY FILES\n6.EXIT\nCHOOSE AN OPTION:");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				printf("\nenter the name of the directory:");
				scanf("%s",dir[dcount].dname);
				dir[dcount].fcount=0;
				dcount++;
				printf("\n%d",dcount);
				break;
			case 2:
				printf("\nenter the name of the directory:");
				scanf("%s",dtemp);
				printf("\nenter the name of the file:");
				scanf("%s",ftemp);
				flag=0;
				for (i=0;i<dcount;i++)
				{
					if (strcmp(dtemp,dir[i].dname)==0)
					{
						for (j=0;j<dir[i].fcount;j++)
						{
							if (strcmp(ftemp,dir[i].fname[j+1])==0)
							{
								printf("\nFILE NAME ALREADY IN USE!!!");
								flag=1;
								break;
							}
						}
						break;
					}
				}
				if (flag==0)
				{
					dir[i].fcount++;
					strcpy(dir[i].fname[dir[i].fcount],ftemp);
					printf("\nFILE CREATED");
					printf("\n%d",dir[i].fcount);
				}
				break;
			case 3:
				printf("\nenter the name of the directory:");
				scanf("%s",dtemp);
				for (i=0;i<dcount;i++)
				{
					if (strcmp(dtemp,dir[i].dname)==0)
					{
						printf("\nenter the name of the file:");
						scanf("%s",ftemp);
						flag=0;
						for (j=0;j<dir[i].fcount;j++)
						{
							if (strcmp(ftemp,dir[i].fname[j+1])==0)
							{
								printf("\nFILE DELETED");
								for (k=j;k<dir[i].fcount;k++)
								{
									strcpy(dir[i].fname[k],dir[i].fname[k+1]);
								}
								flag=1;
								dir[i].fcount--;
								break;
							}
						}
					}
				}
				if (flag==0)
					printf("\nSUCH A FILE DOES NOT EXIST!!!");
				break;
			case 4:
				printf("\nenter the name of the directory:");
				scanf("%s",dtemp);
				flag=0;
				for (i=0;i<dcount;i++)
				{
					if (strcmp(dtemp,dir[i].dname)==0)
					{
						printf("\nenter the name of the file:");
						scanf("%s",ftemp);
						for (j=0;j<dir[i].fcount;j++)
						{
							if (strcmp(ftemp,dir[i].fname[j+1])==0)
							{
								printf("\nfile found");
								flag=1;
								break;
							}
						}
					}
				}
				if (flag==0)
					printf("\nsuch a file not found");
				break;
			case 5:
				for (i=0;i<dcount;i++)
				{
					printf("\n%s",dir[i].dname);
					if (dir[i].fcount==0)
					{
						printf("\n\tdirectory is empty");
					}
					else
					{
						printf("\n%d",dir[i].fcount);
						for (j=0;j<dir[i].fcount;j++)
							printf("\n\t%s",dir[i].fname[j+1]);
					}
				}
				break;
		}
	}
}
						 




						
