#include <iostream>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int a[100000];
int main()
{
	set <int> dog;
	vector <int> check;
	memset(a,-1,sizeof(a));
	int M,N,s1,s2;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>s1>>s2;
		a[s1]=s2;
		a[s2]=s1;
	}
	int temp;
	cin>>M;
	for(int i=0;i<M;i++)
	{
		cin>>temp;
		check.push_back(temp);
	}
	vector <int> :: iterator it_check=check.begin();
	for(;it_check!=check.end();it_check++)
	{
		if(find(check.begin(),check.end(),a[*it_check])==check.end()) dog.insert(*it_check);
	}
	cout<<dog.size()<<endl;
	set <int> :: iterator it_dog=dog.begin();
	for(it_dog=dog.begin();it_dog!=dog.end();it_dog++)
	{
		if(it_dog==dog.begin()) printf("%05d",*it_dog);
		else printf(" %05d",*it_dog);
	}
	return 0;
}
