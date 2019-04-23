#include <iostream>
#include <cmath>
#pragma warning(disable:4996)
using namespace std;
int a[1111][1111];
int f[100000000] = { 0 };
int main()
{
	int m, n, tol;
	scanf("%d%d%d", &m, &n, &tol);
	int x, y, color,Color;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &a[i][j]);
			f[a[i][j]]++;
		}
	}
	int x1, x2, x3, x4, x5, x6, x7, x8;
	int y1, y2, y3, y4, y5, y6, y7, y8;
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (f[a[i][j]] > 1) continue;
			Color=a[i][j];
			x1 = i - 1; y1 = j - 1;
			x2 = i - 1; y2 = j;
			x3 = i - 1; y3 = j + 1;
			x4 = i; y4 = j + 1;
			x5 = i + 1; y5 = j + 1;
			x6 = i + 1; y6 = j;
			x7 = i + 1; y7 = j - 1;
			x8 = i; y8 = j - 1;
			if (x1 >= 0 && x1 < n&&y1 >= 0 && y1 < m) if (fabs(a[x1][y1] - Color) <= tol) continue;
			if (x2 >= 0 && x2 < n&&y2 >= 0 && y2 < m) if (fabs(a[x2][y2] - Color) <= tol) continue;
			if (x3 >= 0 && x3 < n&&y3 >= 0 && y3 < m) if (fabs(a[x3][y3] - Color) <= tol) continue;
			if (x4 >= 0 && x4 < n&&y4 >= 0 && y4 < m) if (fabs(a[x4][y4] - Color) <= tol) continue;
			if (x5 >= 0 && x5 < n&&y5 >= 0 && y5 < m) if (fabs(a[x5][y5] - Color) <= tol) continue;
			if (x6 >= 0 && x6 < n&&y6 >= 0 && y6 < m) if (fabs(a[x6][y6] - Color) <= tol) continue;
			if (x7 >= 0 && x7 < n&&y7 >= 0 && y7 < m) if (fabs(a[x7][y7] - Color) <= tol) continue;
			if (x8 >= 0 && x8 < n&&y8 >= 0 && y8 < m) if (fabs(a[x8][y8] - Color) <= tol) continue;
			x = i; y = j; color = a[i][j];
			flag++;
			if (flag == 2)
			{
				printf("Not Unique");
				return 0;
			}
		}
	}
	if (flag == 0) printf("Not Exist");
	else printf("(%d, %d): %d", y + 1, x + 1, color);
	return 0;
}
