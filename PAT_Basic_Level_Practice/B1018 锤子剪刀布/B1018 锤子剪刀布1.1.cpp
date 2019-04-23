#include <cstdio>
#pragma warning(disable:4996)
int main()
{
	freopen("D://freopen.txt", "r", stdin);
	int h[30][30] = { 0 };
	int aa[200] = { 0 }, bb[200] = { 0 };
	h['C' - 'A']['C' - 'A'] = 0; h['C' - 'A']['J' - 'A'] = 1; h['C' - 'A']['B' - 'A'] = -1;
	h['J' - 'A']['J' - 'A'] = 0; h['J' - 'A']['C' - 'A'] = -1; h['J' - 'A']['B' - 'A'] = 1;
	h['B' - 'A']['B' - 'A'] = 0; h['B' - 'A']['C' - 'A'] = 1; h['B' - 'A']['J' - 'A'] = -1;
	int n, as[5] = { 0 }, bs[5] = { 0 };
	char a,b;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		scanf("%c %c", &a, &b);
		if (h[a - 'A'][b - 'A'] == 1) { as[0]++; bs[2]++; aa[a]++; }
		else if (h[a - 'A'][b - 'A'] == 0) { as[1]++; bs[1]++; }
		else { as[2]++; bs[0]++; bb[b]++; }
		getchar();
	}
	int temp1 = aa['B'], temp2 = bb['B']; char t1='B', t2='B';
	if (temp1 < aa['C']) { temp1 = aa['C']; t1 = 'C'; }
	if (temp1 < aa['J']) { temp1 = aa['J']; t1 = 'J'; }
	if (temp2 < bb['C']) { temp2 = bb['C']; t2 = 'C'; }
	if (temp2 < bb['J']) { temp2 = bb['J']; t2 = 'J'; }
	printf("%d %d %d\n%d %d %d\n%c %c", as[0], as[1], as[2], bs[0], bs[1], bs[2], t1, t2);
	return 0;
}
