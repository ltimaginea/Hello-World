#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int N,len,cnt=0;
	double temp=0.0,sum=0.0;
	bool flag=true;
	char s1[100],s2[100];
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		flag=true;
		scanf("%s",s1);
		len=strlen(s1);
		sscanf(s1,"%lf",&temp);
		sprintf(s2,"%.2lf",temp);
		//printf("%s %lf %s\n",s1,temp,s2);
		for(int j=0;j<len;j++)
		{
			if(s1[j]!=s2[j]) {
				flag=false;
				break;
			}
		}
		if(flag&&temp>=-1000&&temp<=1000)
		{
			cnt++;
			sum+=temp;
		}
		else printf("ERROR: %s is not a legal number\n",s1);
	}
	if(cnt)
	{
		if(cnt==1) printf("The average of 1 number is %.2lf\n",sum);
		else printf("The average of %d numbers is %.2lf\n",cnt,sum*1.0/cnt);
	}
	else printf("The average of 0 numbers is Undefined\n");
	return 0;
}
