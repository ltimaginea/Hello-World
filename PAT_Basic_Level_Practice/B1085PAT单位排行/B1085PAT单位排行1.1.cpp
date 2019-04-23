#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;
struct student{
	char id[20];
	int score;
	string school;
}stu[100010];
struct co{
	int cnt;
	double sumscore;
	string colleg;
	co()
	{
		cnt=0;
		sumscore=-1;
	}
}college[100010];
bool cmp(co a,co b)
{
	if(a.sumscore==b.sumscore) 
	{
		if(a.cnt==b.cnt)
		{
			return a.colleg<b.colleg;
		}
		else 
		{
			return a.cnt<b.cnt;
		}
	}
	else return a.sumscore>b.sumscore;
}
bool flag[100010]={false};
int main()
{
	int N;
	scanf("%d",&N);
	string temp;
	unordered_map <string,int> coll;
	for(int i=0;i<N;i++)
	{
		scanf("%s%d ",&stu[i].id,&stu[i].score);
		cin>>temp;
		int len=temp.size();
		for(int j=0;j<len;j++)
		{
			if(temp[j]<='Z'&&temp[j]>='A') temp[j]=temp[j]+('a'-'A');
		}
		stu[i].school=temp;
		coll[temp]=i;
	}
	for(int i=0;i<N;i++)
	{
		college[coll[stu[i].school]].colleg=stu[i].school;
		college[coll[stu[i].school]].cnt++;
		if(flag[coll[stu[i].school]]==false) college[coll[stu[i].school]].sumscore=0;
		if(stu[i].id[0]=='B') college[coll[stu[i].school]].sumscore+=stu[i].score/1.5;
		else if(stu[i].id[0]=='A') college[coll[stu[i].school]].sumscore+=stu[i].score;
		else college[coll[stu[i].school]].sumscore+=stu[i].score*1.5;
		flag[coll[stu[i].school]]=true;
	}
	int count=0;
	for(int i=0;i<N;i++)
	{
		if(college[i].cnt==0);
		else 
		{
		college[i].sumscore=(int)college[i].sumscore;
		count++; 
		} 
	}
	printf("%d\n",count);
	int sc,hhh;
	sort(college,college+N,cmp);
	for(int i=0;i<count;i++)
	{
		if(i==0) 
		{
			printf("%d ",i+1);
			cout<<college[i].colleg;
			printf(" %d %d\n",(int)college[i].sumscore,college[i].cnt);
			sc=(int)college[i].sumscore;hhh=i;
		}
		else
		{
			if((int)college[i].sumscore==sc);
			else
			{
				hhh=i;
				sc=(int)college[i].sumscore;
			}
			printf("%d ",hhh+1);
			cout<<college[i].colleg;
			printf(" %d %d\n",(int)college[i].sumscore,college[i].cnt);
		}
	}
	return 0;
}
