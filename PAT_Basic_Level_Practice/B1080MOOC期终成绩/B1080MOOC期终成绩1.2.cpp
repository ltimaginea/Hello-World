#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
struct student{
	string id;
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
bool cmp(student a,student b)
{
	if(a.scoree!=b.scoree) return a.scoree>b.scoree;
	else 
	{
		if(a.id<b.id) return true;
		else return false;
	}
}
int main()
{
	int P,M,N;
	string temp;
	int score;
	map <string,int> search;
	scanf("%d%d%d",&P,&M,&N);
	for(int i=0;i<P;i++)
	{
		cin>>temp;
		scanf("%d",&score);
		if(score>=200)
		{
			stu[n].id=temp;
			stu[n].net=score;
			search[temp]=n;
			n++;
		}
	}
	map <string,int> :: iterator it;
	for(int i=0;i<M;i++)
	{
		cin>>temp;
		scanf("%d",&score);
		it=search.find(temp);
		if(it!=search.end())
		{
			stu[it->second].mid=score;
		}
	}
	for(int i=0;i<N;i++)
	{
		cin>>temp;
		scanf("%d",&score);
		it=search.find(temp);
		if(it!=search.end())
		{
			stu[search[temp]].final=score;
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
		{
			cout<<stu[i].id;
			printf(" %d %d %d %d\n",stu[i].net,stu[i].mid,stu[i].final,stu[i].scoree);
		}
	}
	return 0;
}
