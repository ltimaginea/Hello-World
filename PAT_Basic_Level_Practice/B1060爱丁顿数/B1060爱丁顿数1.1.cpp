#include <iostream>
#include <algorithm>
using namespace std;
int a[100010]={0};
int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",a+i);
	}
	sort(a,a+N);
	int temp=min(N,a[N-1]);
	for(int i=temp;i>0;i--)
	{
		temp=upper_bound(a,a+N,i)-a;
		if(N-temp>=i) 
		{
			printf("%d\n",i);
			return 0;
		}
	}
	printf("0");
	return 0;
}
