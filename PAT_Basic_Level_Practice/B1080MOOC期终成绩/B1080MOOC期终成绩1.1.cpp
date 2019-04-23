//此程序最后一个测试点会超时，因为其中多次暴力查找耗时过多！ 
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct student{
	char id[30];
	int net;
	int mid;
	int final;
	int scoree;
	student()
	{
		scoree=0;
		mid=-1;
		final=-1;
	}
}stu[10100];
int n=0;
int is(char temp[])
{
	for(int i=0;i<n;i++)
	{
		if(strcmp(temp,stu[i].id)==0) return i;
	}
	return -1;
}
bool cmp(student a,student b)
{
	if(a.scoree!=b.scoree) return a.scoree>b.scoree;
	else 
	{
		if(strcmp(a.id,b.id)<0) return true;
		else return false;
	}
}
int main()
{
	int P,M,N;
	char temp[30];
	int score;
	scanf("%d%d%d",&P,&M,&N);
	for(int i=0;i<P;i++)
	{
		scanf("%s%d",temp,&score);
		if(score>=200)
		{
			strcpy(stu[n].id,temp);
			stu[n].net=score;
			n++;
		}
		
	}
	int idd;
	for(int i=0;i<M;i++)
	{
		scanf("%s%d",temp,&score);
		idd=is(temp);
		if(idd!=-1)
		{
			stu[idd].mid=score;
		}
	}
	for(int i=0;i<N;i++)
	{
		scanf("%s%d",temp,&score);
		idd=is(temp);
		if(idd!=-1)
		{
			stu[idd].final=score;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(stu[i].mid>stu[i].final) stu[i].scoree=(int)(0.5+stu[i].mid*0.4+stu[i].final*0.6);
		else stu[i].scoree=stu[i].final;
	}
	sort(stu,stu+n,cmp);
	for(int i=0;i<n;i++)
	{
		if(stu[i].scoree>=60)
		printf("%s %d %d %d %d\n",stu[i].id,stu[i].net,stu[i].mid,stu[i].final,stu[i].scoree);
	}
	return 0;
}
