#include <cstdio>
#pragma warning(disable:4996)
#include <cstring>
int main()
{
	int n, cnt[300] = { 0 };
	scanf("%d", &n);
	char ch[110];
	for (int i = 0; i < n; i++)
	{
		scanf("%s", ch);
		memset(cnt, 0, sizeof(cnt));
		int len = strlen(ch);
		int j = 0;
		for (j = 0; j < len; j++)
		{
			cnt[ch[j]]++;
			if (ch[j] == 'A' || ch[j] == 'P' || ch[j] == 'T');
			else {
				printf("NO\n");
				break;
			}
		}
		if (j != len) continue;
		if (cnt['P'] == 1 && cnt['A'] >= 1 && cnt['T'] == 1)
		{
			int chazhi = strstr(ch, "T") - strstr(ch, "P");
			if (chazhi>1)
			{
				int x = 0, y = chazhi - 1, z = 0;
				for (x = 0; ch[x] != 'P'; x++);
				z = len - x - y - 2;
				if (z - x*(y - 1) == x) printf("YES\n");
				else printf("NO\n");
			}
			else printf("NO\n");
		}
		else printf("NO\n");
	}
	return 0;
}