#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
struct student{
	string id;
	int score;
};
struct three{
	string school;
	int number;
};
bool cmp1(student a,student b)
{
	if(a.score==b.score) return a.id<b.id;
	else return a.score>b.score;
}
bool cmp2(three a,three b)
{
	if(a.number==b.number) return a.school<b.school;
	else return a.number>b.number;
}
int main()
{
	//freopen("D://freopen.txt","r",stdin);
	int N,M;
	string temp;
	int s;
	//vector <three> thr3;
	vector <student> stu;
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)
	{
		cin>>temp;
		scanf("%d",&s);
		stu.push_back(student{temp,s});
	}
	sort(stu.begin(),stu.end(),cmp1);
	int len=stu.size();
	for(int i=0;i<M;i++)
	{
		scanf("%d ",&s);
		cin>>temp;
		printf("Case %d: %d ",i+1,s);
		cout<<temp<<endl;
		switch(s)
		{
			case 1:
				{
					bool flag=false;
					for(int j=0;j<len;j++)
					{
						if(stu[j].id[0]==temp[0]) 
						{
							flag=true;
							cout<<stu[j].id;
							printf(" %d\n",stu[j].score);
						}
					}
					if(flag==false) printf("NA\n");
					break;
				}
			case 2:
				{
					bool flag=false;
					int count=0,sum=0;
					for(int j=0;j<len;j++)
					{
						if(stu[j].id.substr(1,3)==temp)
						{
							flag=true;
							count++;
							sum+=stu[j].score;
						}
					}
					if(flag==false)
					{
						printf("NA\n");
						break;
					}
					printf("%d %d\n",count,sum);
					break;
				}
			case 3:
				{
					vector <three> thr3;
					string t;
					bool flag=false;
					unordered_map <string,int> scoree;
					for(int j=0;j<len;j++)
					{
						if(stu[j].id.substr(4,6)==temp)
						{
							flag=true;
							t=stu[j].id.substr(1,3);
							scoree[t]++;
						}
					}
					if(flag==false)
					{
						printf("NA\n");
						break;
					}
					unordered_map <string,int> :: iterator it=scoree.begin();
					for(;it!=scoree.end();it++)
					{
						thr3.push_back(three{it->first,it->second});
					}
					sort(thr3.begin(),thr3.end(),cmp2);
					int l=thr3.size();
					for(int z=0;z<l;z++)
					{
						cout<<thr3[z].school;
						printf(" %d\n",thr3[z].number);
					}
					break;
				}
		}
	}
	return 0;
}
