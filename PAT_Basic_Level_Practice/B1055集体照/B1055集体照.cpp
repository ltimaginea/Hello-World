#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
struct student{
		string name;
		int tall;
	}stu[10010];
bool cmp(student a,student b)
{
	if(a.tall!=b.tall) return a.tall>b.tall;
	else return a.name<b.name;//»òÕßelse{if(a.name<b.name) return true;else return false;} 
}
int main()
{
	int N,K;
	cin>>N>>K;
	int row=K;
	for(int i=0;i<N;i++)
	{
		cin>>stu[i].name>>stu[i].tall;
	}
	sort(stu,stu+N,cmp);
	string left[10010],right[10010];
	int nleft=0,nright=0;
	int temp=N/K+N%K;
	int z=0;
	left[nleft++]=stu[z++].name;
	for(int i=1;i<temp;i++)
	{
		left[nleft++]=stu[z++].name;i++;
		if(i>=temp) break; 
		right[nright++]=stu[z++].name;
	}
	for(int i=nleft-1;i>=0;i--)
	{
		if(i==nleft-1) cout<<left[i];
		else cout<<" "<<left[i];
	}
	for(int i=0;i<nright;i++)
	{
		cout<<" "<<right[i];
	}
	cout<<"\n";
	row--;
	for(int k=0;k<row;k++)
	{
		nleft=0;nright=0;temp=N/K;
		left[nleft++]=stu[z++].name;
		for(int j=1;j<temp;j++)
		{
			left[nleft++]=stu[z++].name;j++;
			if(j>=temp) break; 
			right[nright++]=stu[z++].name;
		}
		for(int i=nleft-1;i>=0;i--)
	{
		if(i==nleft-1) cout<<left[i];
		else cout<<" "<<left[i];
	}
	for(int i=0;i<nright;i++)
	{
		cout<<" "<<right[i];
	}
	cout<<"\n";
	}
	return 0;
}
