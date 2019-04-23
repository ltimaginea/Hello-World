#include <iostream>
#include <cstring>
using namespace std;
struct Item
{
	int score;
	int num;
	int rightnum;
	char answer[10];
	int wrong[10];
	Item ()
	{
		memset(wrong,0,sizeof(wrong));
	}
}item[110];
int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=0,j=0;i<M;i++)
	{
		scanf("%d %d %d",&item[i].score,&item[i].num,&item[i].rightnum);
		for(j=0;j<item[i].rightnum;j++)
		{
			scanf(" %c",&item[i].answer[j]);
		}
	}
	double s=0;
	int n=0,which;
	int err[10];
	char temp;
	for(int i=0;i<N;i++)
	{
		s=0;
		for(int j=0,z=0;j<M;j++)
		{
			which=-1;
			memset(err,0,sizeof(err));
			getchar();
			scanf("(%d",&n);
			for(z=0;z<n;z++)
			{
				scanf(" %c",&temp);
				err[temp-'a']--;
			}
			getchar();
			for(z=0;z<item[j].rightnum;z++)
			{
				err[item[j].answer[z]-'a']++;
			}
			for(z=0;z<item[j].num;z++)
			{
				if(err[z]==-1) 
				{
					item[j].wrong[z]++;
					which=2;
				}
				if(err[z]==1)
				{
					item[j].wrong[z]++;
				}
			}
			if(which==2);
			else 
			{
				if(n==item[j].rightnum) s=s+item[j].score;
				else s=s+item[j].score/2.0;
			}
		}
		printf("%.1lf\n",s);
		
	}
	int maxx=-1;
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<item[i].num;j++)
		{
			if(maxx<item[i].wrong[j]) maxx=item[i].wrong[j];
		}
	}
	if(maxx==0) 
	{
		printf("Too simple\n");
		return 0;
	}
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<item[i].num;j++)
		{
			if(maxx==item[i].wrong[j]) 
			{
				printf("%d %d-%c\n",maxx,i+1,'a'+j);
			}
		}
	}
	return 0;
}
