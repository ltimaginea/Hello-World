#include <iostream>
#pragma warning(disable:4996)
#include <algorithm>
using namespace std;
int main()
{
	freopen("D://freopen.txt", "r", stdin);
	int N, temp, flag = -1, ff = 0;
	scanf("%d", &N);
	int a1 = 0, a2 = 0, a3 = 0, suma4 = 0, na4 = 0, a5 = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		switch (temp%5)
		{
		case 0:if (temp % 2 == 0) a1 += temp; break;
		case 1:ff = 1; flag *= -1; a2 += flag * temp; break;
		case 2:++a3; break;
		case 3:suma4 += temp; ++na4; break;
		case 4:a5 = max(a5, temp);
		}
	}
	if (a1) printf("%d", a1);
	else printf("N");
	if (ff) printf(" %d", a2);
	else printf(" N");
	if (a3) printf(" %d", a3);
	else printf(" N");
	if (suma4) printf(" %.1lf", suma4*1.0 / na4);
	else printf(" N");
	if (a5) printf(" %d", a5);
	else printf(" N");
	return 0;
}