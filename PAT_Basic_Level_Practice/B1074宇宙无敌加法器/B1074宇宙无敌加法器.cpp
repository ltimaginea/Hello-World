#include <iostream>
#include <cstring>
using namespace std;
struct number
{
	int num[100];
	int len;
	number()
	{
		len=0;
		memset(num,0,sizeof(num));
	}
};
void change(char A[],int l,number *a)
{
	for(int i=l-1;i>=0;i--)
	{
		a->num[a->len++]=A[i]-'0';
	}
}
int main()
{
	char A[100],B[100],Pro[100];
	cin>>Pro>>A>>B;
	number a,b,pro,sum;
	change(Pro,strlen(Pro),&pro);
	change(A,strlen(A),&a);
	change(B,strlen(B),&b);
	int temp,i,s=0;
	for(i=0;i<a.len||i<b.len;i++)
	{
		temp=pro.num[i];
		if(pro.num[i]==0) temp=10;
		s=s+a.num[i]+b.num[i];
		sum.num[i]=s%temp;
		s=s/temp;
	}
	for(;s!=0;i++)
	{
		temp=pro.num[i];
		if(pro.num[i]==0) temp=10;
		sum.num[i]=s%temp;
		s=s/temp;
	}
	sum.len=i;
	for(i=sum.len-1;i>0;i--)
	{
		if(sum.num[i]==0) sum.len--;
		else break;
	}
	for(i=sum.len-1;i>=0;i--)
	{
		cout<<sum.num[i];
	}
	return 0;
}
