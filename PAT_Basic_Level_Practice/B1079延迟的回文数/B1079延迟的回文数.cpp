#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct number{
	int len;
	int num[10010];
	number()
	{
		len=0;
		memset(num,0,sizeof(num));
	}
};
void change(number * h,char a[],int l)
{
	for(int i=l-1;i>=0;i--)
	{
		h->num[h->len++]=a[i]-'0';
	}
}
bool is(number h)
{
	for(int i=0,j=h.len-1;i<j;i++,j--)
	{
		if(h.num[i]!=h.num[j]) return false;
	}
	return true;
}
number sum(number hui)
{
	number s;
	int temp=0;
	for(int i=0;i<hui.len;i++)
	{
		temp+=hui.num[i]+hui.num[hui.len-1-i]; 
		s.num[s.len++]=temp%10;
		temp/=10;
	}
	if(temp!=0) s.num[s.len++]=temp;
	return s;
}
int main()
{
	number hui;
	char a[1010];
	cin>>a;
	char A[1010];
	strcpy(A,a);
	reverse(A,A+strlen(A));
	if(strcmp(A,a)==0) 
	{
		cout<<a<<" is a palindromic number.";
		return 0;
	}
	change(&hui,a,strlen(a));
	number s=hui;
	int i=0;
	for(i=0;i<10;i++)
	{
		for(int j=s.len-1;j>=0;j--)
		{
			printf("%d",s.num[j]);
		}
		printf(" + ");
		for(int j=0;j<s.len;j++)
		{
			printf("%d",s.num[j]);
		}
		
		
		printf(" = ");
		s=sum(s);
		for(int j=s.len-1;j>=0;j--)
		{
			printf("%d",s.num[j]);
		}
		printf("\n");
		if(is(s))
		{
			for(int j=s.len-1;j>=0;j--)
		{
			printf("%d",s.num[j]);
		}
			printf(" is a palindromic number.");
			return 0;
		}
		else
		{
			
		}
	}
	if(i==10) printf("Not found in 10 iterations.");
	return 0;
}
