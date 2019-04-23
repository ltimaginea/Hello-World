#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int main()
{
	int ch;
	int N;
	scanf("%d %d",&ch,&N);
	if(N==1)
	{
		printf("%d",ch);
		return 0;
	}
	if(N==2)
	{
		printf("%d1",ch);
		return 0;
	}
	vector <int> a[50];
	a[2].push_back(ch);
	a[2].push_back(1);
	int temp,cnt=0;
	for(int j=2;j<N;j++)
	{
		for(int z=0,i=0;z<a[j].size();z=i)
		{
			cnt=0;
			temp=a[j][z];
			for(i=z;i<a[j].size();i++)
			{
				if(temp==a[j][i]) cnt++;
				else break;
			}
			a[j+1].push_back(temp);
			a[j+1].push_back(cnt);
		}
		
	}
	for(int i=0;i<a[N].size();i++)
	{
		printf("%d",a[N][i]);
	}
	return 0;
}
