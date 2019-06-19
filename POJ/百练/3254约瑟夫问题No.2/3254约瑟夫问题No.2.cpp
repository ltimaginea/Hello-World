#include <iostream>
#include <cstdio>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
int main()
{
	int n, m, p;
	bool s[310] = { false };
	cin >> n >> p >> m;
	for (int cnt=0; n != 0;cnt=0 )
	{
		fill(s, s + 310, false);
		for (int j=p-2; cnt != n;)
		{
			for (int i=0; i < m; )
			{
				j++;
				if (s[j%n] == false) { i++; }
			}
			s[j%n] = true; cnt++;
			if (cnt == 1) cout << j % n + 1;
			else cout << "," << j % n + 1;
		}
		cout << endl;
		cin >> n >> p >> m;
	}
	return 0;
}
