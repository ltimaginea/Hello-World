#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int a[100000];
int main()
{
	memset(a,-1,sizeof(a));
	int N,s1,s2;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>s1>>s2;
		a[s1]=s2;
		a[s2]=s1;
	}
	int M,m[10010],cnt=0,n=0;
	int A[100010]={0};
	cin>>M;
	int tt[10010];
	for(int i=0;i<M;i++)
	{
		cin>>s1;
		if(a[s1]==-1)
		{
			m[n++]=s1;
		}
		else
		{
			tt[cnt++]=s1;
			A[s1]=1;
		}
	}
	for(int i=0;i<cnt;i++)
	{
		if(A[a[tt[i]]]==1) ;
		else m[n++]=tt[i];
	}
	printf("%d\n",n);
	sort(m,m+n);
	for(int i=0;i<n;i++)
	{
		if(i==0) printf("%05d",m[i]);
		else printf(" %05d",m[i]);
	}
	return 0;
}
