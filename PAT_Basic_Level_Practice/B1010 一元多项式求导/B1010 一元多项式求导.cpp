#include <iostream>
using namespace std;
int main()
{
	int zhi, xi, flag = 0;
	for (; cin >> xi >> zhi;) {
		if (zhi) {
			if (flag) printf(" %d %d", xi*zhi, zhi - 1);
			else {
				printf("%d %d", xi*zhi, zhi - 1);
				flag = 1;
			}
		}
	}
	if (flag == 0) printf("0 0");
	return 0;
}