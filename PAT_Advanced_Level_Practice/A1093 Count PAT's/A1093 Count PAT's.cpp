#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;
char str[100010];
int p[100010], t[100010];
int main()
{
	long long n = 0;
	scanf("%s", str);
	int len = strlen(str);
	for (int i = 1; i < len; i++) {
		if (str[i - 1] == 'P') p[i] = p[i - 1] + 1;
		else p[i] = p[i - 1];
	}
	for (int i = len - 2; i >= 0; i--) {
		if (str[i + 1] == 'T') t[i] = t[i + 1] + 1;
		else t[i] = t[i + 1];
	}
	for (int i = 1; i < len-1; i++) {
		if (str[i] == 'A') n += p[i] * t[i];
	}
	printf("%lld", n % 1000000007);
	return 0;
}