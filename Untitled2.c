#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
	char p[10][5],temp[5];
	int i,j,pt[10],wt[10],totwt=0,pr[10],temp1,n;
	float avgwt;
	printf("Enter no of STUDENTS:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter student %d name:",i+1);
  		scanf("%s",&p[i]);
		printf("enter process time:");
		scanf("%d",&pt[i]);
		printf("enter no of gifts:");
		scanf("%d",&pr[i]);
	}
  	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(pr[i]>pr[j])
			{
				temp1=pr[i];
				pr[i]=pr[j];
				pr[j]=temp1;
				temp1=pt[i];
				pt[i]=pt[j];
				pt[j]=temp1;
				strcpy(temp,p[i]);
				strcpy(p[i],p[j]);
				strcpy(p[j],temp);
			}
		}
	}
	wt[0]=0;
	for(i=1;i<n;i++)
	{
		wt[i]=wt[i-1]+pr[i-1];
		totwt=totwt+wt[i];
	}
	avgwt=(float)totwt/n;
	printf("s_name\t P_time\t No.Gifts\tW_time\n");
	for(i=0;i<n;i++)
	{
	   printf(" %s\t %d\t %d\t \t%d\n" ,p[n-i],pt[n-i],pr[n-i],wt[n-i]);
	}
	printf("total waiting time=%d\navg waiting time=%f",totwt,avgwt);
	getch();
}
