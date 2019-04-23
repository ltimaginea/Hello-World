#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;
int main()
{
	int n, day = 0, number = 0, max = 20150000, min = 18130000;
	cin >> n;
	char temp[8], Long[8], Short[8];
	int yy, mm, dd;
	for (int i = 0; i < n; i++) {
		scanf("%s%d/%d/%d", temp, &yy, &mm, &dd);
		day = yy * 10000 + mm * 100 + dd;
		if ((20140906 >= day)&&(18140906<=day)) {
			number++;
			if (day < max) {
				max = day;
				strcpy(Long, temp);
			}
			if (day > min) {
				min = day;
				strcpy(Short, temp);
			}
		}
	}
	if (number == 0) printf("0\n");//有效个数为0时，则特判输出; 
	else printf("%d %s %s\n", number, Long, Short);
	return 0;
}
