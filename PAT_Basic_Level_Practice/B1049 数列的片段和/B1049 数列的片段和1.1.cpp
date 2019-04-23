//测试点3失败，可能是由于中间环节多次处理，造成最终结果精度不够. 
#include <iostream>
#pragma warning(disable:4996)
using namespace std;
double temp[100010];
int main()
{
	int N;
	scanf("%d", &N);
	double sum = 0.0, t = 0.0;
	for (int i = 0; i < N; i++)
	{
		scanf("%lf", &temp[i]);
	}
	for (int j = 0; j < N; j++)
	{
		t = t + temp[j];
		sum = sum + t;
	}
	t = sum;
	for (int j = 1; j < N; j++)
	{
		t = t - (N + 1 - j)*temp[j - 1];
		sum = t + sum;
	}
	printf("%.2lf\n", sum);
	return 0;
}
