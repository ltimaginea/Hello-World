//�˳���ּ����ʾvector������Ϊ�ṹ��ʱ������������ݺͲ������ݣ���ʵ����ĿҪ��
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
struct colleg {
	string name;
	int sumscore;
	int n;
};
bool cmp(colleg a, colleg b)
{
	if (a.sumscore == b.sumscore)
	{
		if (a.n == b.n)
		{
			return a.name < b.name;
		}
		else
		{
			return a.n < b.n;
		}
	}
	else return a.sumscore > b.sumscore;
}
//�˴�����"=="��Ϊʵ�ֲ�����Ƚṹ�塣
bool operator ==(const colleg & a, const colleg & b)
{
	return a.name == b.name&&a.sumscore == b.sumscore&&a.n == b.n;
}
//�˴�����"=="��Ϊʵ�ֲ��ҽṹ������ȵ�ĳ��Ԫ�صĽṹ�塣
bool operator ==(const colleg & a, string tempp)
{
	return a.name == tempp;
}
int main()
{
	int N;
	vector <colleg> know;
	unordered_map <string, int> cnt;
	unordered_map <string, double> sum;
	scanf("%d", &N);
	char id[20];
	int score;
	string school;
	for (int i = 0; i < N; i++)
	{
		scanf("%s%d", id, &score);
		cin >> school;
		int len = school.size();
		for (int j = 0; j < len; j++)
		{
			if (school[j] <= 'Z'&&school[j] >= 'A') school[j] += ('a' - 'A');
		}
		cnt[school]++;
		if (id[0] == 'B') sum[school] += score / 1.5;
		else if (id[0] == 'A') sum[school] += score;
		else sum[school] += score * 1.5;
	}
	unordered_map <string, int> ::iterator it = cnt.begin();
	for (; it != cnt.end(); it++)
	{
		//�������ݡ�
		know.push_back(colleg{ it->first,(int)sum[it->first],it->second });
	}
	sort(know.begin(), know.end(), cmp);
	vector <colleg> ::iterator itfind,it0;
	it0 = know.end();
	it0--;
	string tempp = "lanx";
	//(1)������ȵĽṹ�巽��һ��
	//itfind = find(know.begin(), know.end(), *it0);
	//(2)������ȵĽṹ�巽������
	itfind = find(know.begin(), know.end(), colleg{"lanx",81,2});
	//(3)���ҽṹ������ȵ�ĳ��Ԫ�صĽṹ�塣
	//itfind = find(know.begin(), know.end(), tempp);
	cout << (*itfind).name << " " << itfind->sumscore << " " << itfind->n << endl;
	return 0;
}