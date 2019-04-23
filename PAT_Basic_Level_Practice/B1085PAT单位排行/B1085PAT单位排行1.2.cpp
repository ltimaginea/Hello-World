#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct colleg{
	string name;
	int sumscore;
	int n;
};
bool cmp(colleg a,colleg b)
{
	if(a.sumscore==b.sumscore)
	{
		if(a.n==b.n)
		{
			return a.name<b.name;
		}
		else
		{
			return a.n<b.n;
		}
	}
	else return a.sumscore>b.sumscore;
}
int main()
{
	int N;
	vector <colleg> know;
	unordered_map <string,int> cnt;
	unordered_map <string,double> sum;
	scanf("%d",&N);
	char id[20];
	int score;
	string school;
	for(int i=0;i<N;i++)
	{
		scanf("%s%d",id,&score);
		cin>>school;
		int len=school.size();
		for(int j=0;j<len;j++)
		{
			if(school[j]<='Z'&&school[j]>='A') school[j]+=('a'-'A');
		}
		cnt[school]++;
		if(id[0]=='B') sum[school]+=score/1.5;
		else if(id[0]=='A') sum[school]+=score;
		else sum[school]+=score*1.5;
	}
	unordered_map <string,int> :: iterator it=cnt.begin();
	for(;it!=cnt.end();it++)
	{
		know.push_back(colleg{it->first,(int)sum[it->first],it->second});
	}
	int number=know.size();
	printf("%d\n",number);
	sort(know.begin(),know.end(),cmp);
	int Score,count;
	for(int i=0;i<number;i++)
	{
		if(i==0)
		{
			printf("%d ",i+1);
			cout<<know[i].name;
			printf(" %d %d\n",know[i].sumscore,know[i].n);
			Score=know[i].sumscore;
			count=i;
		}
		else
		{
			if(know[i].sumscore!=Score) 
			{
				Score=know[i].sumscore;
				count=i;
			}
			printf("%d ",count+1);
			cout<<know[i].name;
			printf(" %d %d\n",know[i].sumscore,know[i].n);
		}
	}
	return 0;
}
