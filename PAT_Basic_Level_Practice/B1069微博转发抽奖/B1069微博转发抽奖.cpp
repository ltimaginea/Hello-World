#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;
int main()
{
	int n,m,s;
	cin>>m>>n>>s;
	vector <string> save;
	map <string,int> only;
	string temp;
	int a[1010]={0};
	for(int i=0;i<m;i++)
	{
		cin>>temp;
		save.push_back(temp);
		only[temp]=i;
	}
	if(s>m) 
	{
		cout<<"Keep going...";
		return 0;
	}
	vector <string> :: iterator it=save.begin();
	for(int i=1;i<s;i++)
	{
		it++;
	}
	for(;it!=save.end();)
	{
		if(a[only[*it]]!=-1)
		{
			cout<<*it<<endl;
			a[only[*it]]=-1;
		}
		it++;
		for(int i=0;i<n&&it!=save.end();)
		{ 
			if(a[only[*it]]!=-1)
			{
				i++;
			}
			if(i==n) break;
			it++;
		}
	}
	return 0;
}
