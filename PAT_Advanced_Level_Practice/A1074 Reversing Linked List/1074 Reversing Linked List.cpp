#include <iostream>
#pragma warning(disable:4996)
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct Node {
	int address, data, next;
	int order;
}node[maxn];
bool cmp(Node a, Node b) {
	return a.order < b.order;
}
int main()
{
	for (int j = 0; j < maxn; j++)
	{
		node[j].order = maxn;
	}
	int head, N, K, address, cnt = 0;
	scanf("%d%d%d", &head, &N, &K);
	int i = 0;
	for (i = 0; i < N; i++)
	{
		scanf("%d", &address);
		node[address].address = address;
		scanf("%d%d", &node[address].data, &node[address].next);
	}
	address = head;
	for (int j = 1; j <= i; j++)
	{
		node[address].order = j;
		address = node[address].next;
		cnt++;
		if (address == -1) break;//可能存在多余无效的结点，通过cnt统计实际结点数！
	}
	sort(node, node + maxn, cmp);
	int a = cnt - cnt % K;
	for (int j = K; j <= a; j+=K)
	{
		int z;
		for (z = j-1; z >j-K; z--)
		{
			printf("%05d %d %05d\n", node[z].address, node[z].data, node[z - 1].address);
		}
		if (cnt%K == 0)
		{
			if (j == a) {
				printf("%05d %d -1\n", node[z].address, node[z].data);
			}
			else {
				printf("%05d %d %05d\n", node[z].address, node[z].data, node[j + K - 1].address);
			}
		}
		else {
			if(j==a) printf("%05d %d %05d\n", node[z].address, node[z].data, node[j].address);
			else printf("%05d %d %05d\n", node[z].address, node[z].data, node[j + K - 1].address);
		}
	}
	int b = cnt % K;
	for (int j = 0; j < b; j++)
	{
		if (j != b-1) printf("%05d %d %05d\n", node[a].address, node[a].data, node[a].next);
		else printf("%05d %d -1\n", node[a].address, node[a].data);
		a++;
	}
	return 0;
}