#include <iostream>
#include <cstring>
using namespace std;
int main ()
{
	int num,cnt=0;
	char passport[25],temp[100000];
	cin>>passport>>num;
	getchar();
	for(cin.getline(temp,100000);strcmp(temp,"#")!=0;cin.getline(temp,100000))
	{
		if(strcmp(passport,temp)!=0)
		{
			cout<<"Wrong password: "<<temp<<endl;
			cnt++;
		}
		else 
		{
			cout<<"Welcome in";
			return 0;
		}
		if(cnt==num)
		{
			cout<<"Account locked";
			return 0;
		}
	}
	return 0;
}
