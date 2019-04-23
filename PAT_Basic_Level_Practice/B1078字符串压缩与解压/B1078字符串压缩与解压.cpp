#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	char ch,str[1010];
	cin>>ch;
	getchar();
	cin.getline(str,1010);
	int len=strlen(str),n=0;
	if(ch=='C')
	{
		for(int j=0,i=0;j<len;j=i)
		{
			n=1;
			for(i=j+1;i<len;i++)
			{
				if(str[i]==str[i-1])
				{
					n++;
				}
				else break;
			}
			if(n!=1) printf("%d%c",n,str[j]);
			else printf("%c",str[j]);
		}
	}
	else 
	{
		for(int j=0,i=0;i<len;i=j+1)
		{
			n=0;
			for(j=i;j<len;j++)
			{
				if(str[j]<='9'&&str[j]>='0') n=n*10+str[j]-'0';
				else break;
			}
			if(n==0) n=1;
			for(int z=0;z<n;z++)
			{
				printf("%c",str[j]);
			}
		}
	}
	return 0;
}
