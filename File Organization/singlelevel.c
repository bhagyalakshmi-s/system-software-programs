#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	char fname[10][10],dname[10],temp[10];
	int i,j,choice=0,fcount=0,flag=0;
	printf("enter the name of the directory:");
	scanf("%s",dname);
	while (choice != 5)
	{
		printf("\n1.CREATE FILE\n2.DELETE FILE\n3.SEARCH FILE\n4.DISPLAY FILES\n5.EXIT\nCHOOSE AN OPTION:");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				printf("\nenter the name of the file:");
				scanf("%s",temp);
				flag=0;
				for (i=0;i<fcount;i++)
				{
					if (strcmp(temp,fname[i])==0)
					{
						printf("\nFILE NAME ALREADY IN USE!!!");
						flag=1;
						break;
					}
				}
				if (flag==0)
				{
					fcount++;
					strcpy(fname[fcount],temp);
					printf("\nFILE CREATED");
				}
				printf("\n%d",fcount);
				break;
			case 2:
				printf("\nenter the name of the file:");
				scanf("%s",temp);
				flag=0;
				for (i=0;i<fcount;i++)
				{
					if (strcmp(temp,fname[i])==0)
					{
						printf("\nFILE DELETED");
						for (j=i;j<fcount;j++)
						{
							strcpy(fname[j],fname[j+1]);
						}
						flag=1;
						fcount--;
						break;
					}
				}
				if (flag==0)
					printf("\nSUCH A FILE DOES NOT EXIST!!!");
				break;
			case 3:
				printf("\nenter the name of the file:");
				scanf("%s",temp);
				flag=0;
				for (i=0;i<fcount;i++)
				{
					if (strcmp(temp,fname[i])==0)
					{
						printf("\nFILE FOUND");
						flag=1;
						break;
					}
				}
				if (flag==0)
					printf("\nSUCH A FILE DOES NOT EXIST!!!");
				break;
			case 4:
				if (fcount==0)
					printf("DIRECTORY DOES NOT EXIST!!!");
				else
				{
					printf("%s\n\nfiles are:\n",dname);
					for (i=0;i<fcount;i++)
						printf("%s\n",fname[i]);
				}
				break;
		}
	}	
}
