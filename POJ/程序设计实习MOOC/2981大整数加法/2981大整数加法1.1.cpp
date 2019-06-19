#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;
struct number {
	int n[210];
	int len;
	number()
	{
		len = 0;
		memset(n, 0, sizeof(n));
	}
};
number change(char *a,int alen)
{
	number c;
	int i = 0;
	for (i = 0; i < alen; i++)
	{
		if (a[i] == '0') continue;
		else break;
	}
	if (i == alen) {
		c.len = 1;
		return c;
	}
	for (int j=alen-1;j>=i; j--)
	{
		c.n[c.len++] = a[j] - '0';
	}
	return c;
}
number add(number aa, number bb)
{
	number c;
	int temp = 0;
	int aalen = aa.len, bblen = bb.len;
	for (int i = 0; i < aalen || i < bblen; i++)
	{
		temp += aa.n[i] + bb.n[i];
		c.n[c.len++] = temp % 10;
		temp /= 10;
	}
	if (temp != 0) c.n[c.len++] = temp;
	return c;
}
void print(number c)
{
	for (int i = c.len-1; i >=0; i--)
	{
		printf("%d", c.n[i]);
	}
}
int main()
{
	char a[210], b[210];
	scanf("%s%s", a, b);
	int alen = strlen(a), blen = strlen(b);
	number aa = change(a, alen), bb = change(b, blen);
	number d = add(aa, bb);
	print(d);
	return 0;
}