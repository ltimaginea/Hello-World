#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	freopen("D://freopen.txt","r",stdin);
	int N,a[110]={0};
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&a[i]);
	}
	int lier1,lier2,n=0;
	int t[110];
	for(int i=1;i<N;i++)
	{
		for(int j=i+1;j<=N;j++)
		{
			fill(t,t+110,1);
			t[i]=-1;t[j]=-1;
			n=0;
			for(int z=1;z<=N;z++)
			{
				if(a[z]*t[abs(a[z])]<0) {
					n++;
					if(n==1) lier1=z;
					else if(n==2) lier2=z;
					else break;
				}
			}
			if((n==2)&&(t[lier1]*t[lier2]<0)) {
				printf("%d %d",i,j);
				return 0;
			}
		}
	}
	printf("No Solution");
	return 0;
}
