#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int gcd(int a,int b)
{
	if(b==0) return a;
	else return gcd(b,a%b);
}
int main()
{
	bool flag=false;
	double a,b;
	int N1,M1,N2,M2,K;
	scanf("%d/%d %d/%d %d",&N1,&M1,&N2,&M2,&K);
	if((N1*K*1.0/M1)>(N2*K*1.0/M2)) {
		
		a=floor(N1*K*1.0/M1);b=ceil(N2*K*1.0/M2);
		if(a==(N1*K*1.0/M1)) a=a-1;
		if(b==(N2*K*1.0/M2)) b=b+1;
	}
	else {
		a=ceil(N1*K*1.0/M1);b=floor(N2*K*1.0/M2);
		if(a==(N1*K*1.0/M1)) a=a+1;
		if(b==(N2*K*1.0/M2)) b=b-1;
	}
	int ma=max(a,b),mi=min(a,b);
	for(int i=mi;i<=ma;i++)
	{
		if(gcd(K,i)==1)
		{
			if(flag==false)
			{
				printf("%d/%d",i,K);
				flag=true;
			}
			else
			{
				printf(" %d/%d",i,K);
			}
		}
	}
	return 0;
}
