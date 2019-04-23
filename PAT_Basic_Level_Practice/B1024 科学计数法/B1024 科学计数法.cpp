#include <cstdio>
#include <cstring>
#pragma warning(disable:4996)
char s1[10100], s2[10100], s[10100];
int main() {
	scanf("%s", s);
	bool flag1, flag2;
	if (s[0] == '-') flag1 = false;
	else flag1 = true;
	strncpy(s1, s + 1, 2);
	s1[1] = '\0';
	int temp = strstr(s, "E") - s;
	strncpy(s2, s + 3, temp);
	s2[temp - 3] = '\0';
	if (s[temp + 1] == '-') flag2 = false;
	else flag2 = true;
	strcat(s1, s2);
	int c;
	strcpy(s, s + temp + 1);
	sscanf(s, "%d", &c);
	c++;
	if (c < 0) c = -c;
	int n = strlen(s1);
	if (flag1 == false) printf("-");
	if (flag2) {
		if (n > c) {
			int i = 0;
			for (i = 0; i < c; i++) {
				printf("%c", s1[i]);
			}
			if (c == 0) printf("0.");
			else printf(".");
			for (; i < n; i++) {
				printf("%c", s1[i]);
			}
		}
		else {
			printf("%s", s1);
			for (int i = 0; i < c - n; i++) {
				printf("0");
			}
		}
	}
	else {
		printf("0.");
		for (int i = 0; i < c; i++) {
			printf("0");
		}
		printf("%s", s1);
	}
	return 0;
}