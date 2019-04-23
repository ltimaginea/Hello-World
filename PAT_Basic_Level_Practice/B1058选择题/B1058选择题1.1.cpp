#include <iostream>
#pragma warning(disable:4996)
using namespace std;
struct ite {
	int maxscore;
	int num;
	int rightnum;
	char choice[10];
}item[110];
int main()
{
	//freopen("D://freopen.txt", "r", stdin);
	int mm = -1;
	int cnt[110] = { 0 };
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0, j = 0; i < M; i++)
	{
		scanf("%d %d %d", &item[i].maxscore, &item[i].num, &item[i].rightnum);
		for (j = 0; j < item[i].rightnum; j++)
		{
			scanf(" %c", &item[i].choice[j]);
		}
		item[i].choice[j++] = '\0';
	}
	bool flag = true;
	char temp[10][10];
	for (int i = 0; i < N; i++)
	{
		int score = 0;
		for (int j = 0; j < M; j++)
		{
			getchar();
			int t;
			scanf("(%d ", &t);
			for (int z = 0; z < t; z++)
			{
				scanf("%s", temp[z]);
			}
			if (t == item[j].rightnum) {
				int z = 0;
				for (z = 0; z < t; z++)
				{
					if (item[j].choice[z] == temp[z][0]);
					else {
						cnt[j]++;
						flag = false;
						break;
					}
				}
				if (z == t) score += item[j].maxscore;
			}
			else { flag = false; cnt[j]++;}
		}
		printf("%d\n", score);
	}
	if (flag)
	{
		printf("Too simple");
		return 0;
	}
	for (int i = 0; i < M; i++)
		if (mm < cnt[i]) mm = cnt[i];
	printf("%d", mm);
	for(int i=0;i<M;i++)
		if (mm == cnt[i]) {
			printf(" %d", i + 1);
		}
	return 0;
}
