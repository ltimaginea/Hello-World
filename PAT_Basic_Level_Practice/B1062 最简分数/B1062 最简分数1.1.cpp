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
	int N1,M1,N2,M2,K;
	scanf("%d/%d %d/%d %d",&N1,&M1,&N2,&M2,&K);
	double s1=N1*1.0/M1,s2=N2*1.0/M2;
	double ma=max(s1,s2),mi=min(s1,s2);
	for(int i=1;i*1.0/K<ma;i++)
	{
		if(i*1.0/K<=mi) continue;
		else {
			if(gcd(i,K)==1) {
				if(flag==false) {
					printf("%d/%d",i,K);
					flag=true;
				}
				else printf(" %d/%d",i,K);
			}
		}
	}
	return 0;
}
