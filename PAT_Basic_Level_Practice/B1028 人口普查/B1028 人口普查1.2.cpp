#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n, number = 0;
	cin >> n;
	string s, smax = "2014/09/06", smin = "1814/09/06", namemax, namemin, name;
	for (int i = 0; i < n; i++)
	{
		cin >> name;
		cin >> s;
		if (s <= "2014/09/06" && s >= "1814/09/06") {
			number++;
			if (s <= smax) {
				smax = s;
				namemax = name;
			}
			if (s >= smin) {
				smin = s;
				namemin = name;
			}
		}
	}
	cout << number;
	if (number) cout << " " << namemax << " " << namemin;
	return 0;
}