#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
	int temp,n;
	cin>>n;
	vector <int> a;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		a.push_back(temp);
	}
	sort(a.begin(),a.end());
	vector <int> :: iterator it=a.begin();
	double sum=*it;
	for(it++;it!=a.end();it++)
	{
		sum=sum/2.0+*it/2.0;
		
	}
	cout<<floor(sum);
	return 0;
}
