#include<stdio.h>
#include<stdlib.h>
void lc();
int n,m,i,j,t[50][50],d[50],s[50],df[50],dw[50],c[50][50];
int sumd=0,min,sums=0;
void main()
{
	printf("Enter number of factories\n");
	scanf("%d",&m);
	printf("Enter number of shops/warehouses\n");
	scanf("%d",&n);
	printf("Enter the cost per factory and shop\n");
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&t[i][j]);
		}
	}
	printf("Enter the factory capacities\n");
	for(i=1;i<=m;i++)
	{
		scanf("%d",&s[i]);
		sums+=s[i];
	}
	printf("Enter the Store demand\n");
	for(j=1;j<=n;j++)
	{
		scanf("%d",&d[j]);
		sumd+=d[j];
	}
	printf("Entered cost are\n");
	printf("\t\t");
	for(j=1;j<=n;j++)
        {
        	printf("S%d\t",j);
        }
	printf("FS");
	printf("\n");
	for(i=1;i<=m;i++)
	{
		printf("F%d\t",i);
		printf("|\t");
		for(j=1;j<=n;j++)
		{
			printf("%d\t",t[i][j]);

		}
		printf("%d",s[i]);
		printf("\n");
		if(i==m)
		{
			printf("SD\t");
			printf("|\t");
		}
		for(j=1;j<=n&&i==m;j++)
		{
			printf("%d\t",d[j]);
		}
	}
	printf("\n");
	printf("SumD = %d\n",sumd);
	printf("SumS = %d\n",sums);
	lc();
}
void lc()
{
	int S=0,count=0,min1=0;
	if(sumd!=sums)
	{
		printf("Unbalanced transportation problem\n");
	}
	else
	{
		printf("The cost of factories to warehuse is\n");
		while(count<n*m)
		{
			min=100;
			for(i=1;i<=m;i++)
			{
				for(j=1;j<=n;j++)
				{
					c[i][j]=0;
					if(t[i][j]<=min && t[i][j]>min1)
					{
						min=t[i][j];
					}
				}
			}
			//printf("The cost of factories to warehuse is\n");
			for(i=1;i<=m;i++)
			{
				for(j=1;j<=n;j++)
				{
					if(t[i][j]==min&&s[i]!=0&&d[j]!=0)
					{
						if(d[j]>=s[i])
						{
							df[i]=i;
							dw[j]=j;
							S=S+(t[i][j]*s[i]);
							c[i][j]=(t[i][j]*s[i]);
							printf("The cost from factory--->%d to warehouse--->%d is %d\n",df[i],dw[j],c[i][j]);
							d[j]=d[j]-s[i];
							s[i]=0;
						}
						else if(d[j]<=s[i])
						{
							df[i]=i;
                                                        dw[j]=j;
                                                        S=S+(t[i][j]*d[j]);
							c[i][j]=(t[i][j]*d[j]);
							printf("The cost from factory--->%d to warehouse--->%d is %d\n",df[i],dw[j],c[i][j]);
							s[i]=s[i]-d[j];
							d[j]=0;
						}
					}
				}
			}
			min1=min;
			count++;
		}
	}
	/*printf("The cost of factories to warehuse is\n");
        for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
        	{
			if(c[i][j]>0)
			{
        			printf("the cost %d-%d is %d\n",df[i],dw[j],c[i][j]);
        		}
		}
	}*/
        printf("Total transportation cost is %d\n",S);
}
