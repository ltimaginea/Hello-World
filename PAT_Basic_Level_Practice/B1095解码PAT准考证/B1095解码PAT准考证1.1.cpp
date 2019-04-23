#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct ID{
	char K;
	int address;
	int time;
	int number;
	long long count;
	int score;
}stu[10010];
struct three{
					int addre,num;
					three(){
						num=0;addre=0;
					}
				};
bool cmp1(ID a,ID b)
{
	if(a.score==b.score) return a.count<b.count;
	else return a.score>b.score;
}
bool cmp2(three a,three b)
{
	if(a.num==b.num) return a.addre<b.addre;
	else return a.num>b.num;
}
int main()
{
	//freopen("D://freopen.txt","r",stdin);
	int N,M;
	scanf("%d%d\n",&N,&M);
	for(int i=0;i<N;i++)
	{
		//getchar();
		scanf("%c%lld %d\n",&stu[i].K,&stu[i].count,&stu[i].score);
		stu[i].number=stu[i].count%1000;
		stu[i].time=stu[i].count/1000%1000000;
		stu[i].address=stu[i].count/1000/1000000;
	}
	sort(stu,stu+N,cmp1);
	for(int i=1;i<=M;i++)
	{
		int temp;char t;int at;
		scanf("%d",&temp);
		if(temp==1) scanf(" %c",&t);
		else scanf(" %d",&at);
		switch(temp)
		{
			case 1:{
				printf("Case %d: 1 %c\n",i,t);
				//sort(stu,stu+N,cmp1);
				int flag=0;
				for(int j=0;j<N;j++)
				{
					if(stu[j].K==t) {
						printf("%c%012lld %d\n",t,stu[j].count,stu[j].score);
						flag=1;
					}
				}
				if(flag==0) printf("NA\n");
				break;
			}
			case 2:{
				printf("Case %d: 2 %03d\n",i,at);
				int nn=0,nnscore=0,flag=0;
				for(int i=0;i<N;i++)
				{
					if(at==stu[i].address) {
						nn++;nnscore+=stu[i].score;flag=1;
					}
				}
				if(flag==1) printf("%d %d\n",nn,nnscore);
				else printf("NA\n");
				break;
			}
			case 3:{
				three thr[10010];
				printf("Case %d: 3 %06d\n",i,at);
				
				int flag=0;
				for(int i=0;i<N;i++)
				{
					if(at==stu[i].time) {
						thr[stu[i].address].addre=stu[i].address;
						thr[stu[i].address].num++;
					}
				}
				sort(thr,thr+10010,cmp2);
				for(int i=0;i<10010;i++)
				{
					if(thr[i].num) {
						printf("%03d %d\n",thr[i].addre,thr[i].num);
						flag=1;
					}
				}
				if(flag==0) printf("NA\n");
				break;
			}
		}
	}
	return 0;
}
