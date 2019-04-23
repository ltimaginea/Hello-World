#include <iostream>
#include <cmath>
#pragma warning(disable:4996)
using namespace std;
bool isPrime(int a)
{
	if (a <= 1) return false;
	int sqr = (int)sqrt(a);
	for (int i = 2; i <= sqr; i++)
	{
		if (a%i == 0) return false;
	}
	return true;
}
int change(char* s)
{
	int a = 0;
	for (; *s; s++)
		a = a * 10 + *s - '0';
	return a;
}
int main()
{
	int L, K, number;
	cin >> L >> K;
	char *s, temp, t[1010];
	s = t;
	cin >> s;
	for (; *(s + K - 1); ++s)
	{
		temp = *(s + K);
		*(s + K) = '\0';
		number = change(s);
		//sscanf(s, "%d", &number);
		if (isPrime(number)) {
			cout << s;
			return 0;
		}
		else *(s + K) = temp;
	}
	cout << "404";
	return 0;
}
