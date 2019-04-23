#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
bool isPrime(int n)
{
	if(n==1) return false;
	int sqr=(int)sqrt(n);
	for(int i=2;i<=sqr;i++)
	{
		if(n%i==0) return false;
	}
	return true;
}
int main()
{
	freopen("D://freopen.txt","r",stdin);
	int L,K,n;
	scanf("%d%d",&L,&K);
	char a[1010],temp[1010];
	scanf("%s",a);
	for(int i=0;i+K<=L;i++)
	{
		strncpy(temp,a+i,K);
		temp[K]='\0';
		sscanf(temp,"%d",&n);
		if(isPrime(n)) {
			printf("%s\n",temp);
			return 0;
		}
	}
	printf("404\n");
	return 0;
}
