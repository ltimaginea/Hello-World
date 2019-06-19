#include <iostream>
#pragma warning (disable:4996)
using namespace std;
#define ERROR -1
#define Error NULL
typedef int ElementType;
typedef struct LNode * PtrToNode;
struct  LNode {
	ElementType Data;
	PtrToNode Next;
};
typedef PtrToNode Position;
typedef PtrToNode List;
List InitList()
{
	List L = (List)malloc(sizeof(struct LNode));
	L->Next = NULL;
	return L;
}
int Length(List L)
{
	Position temp = L;
	int length = 0;
	while (temp->Next)
	{
		length++;
		temp = temp->Next;
	}
	return length;
}
ElementType FindKth(int i, List L)
{
	if (i < 1) return ERROR;
	Position temp = L;
	int cnt = 0;
	while (temp->Next)
	{
		cnt++;
		temp = temp->Next;
		if (cnt == i) break;
	}
	if (cnt == i) return temp->Data;
	else return ERROR;
}int Find(List L, int i)
{
	List temp = L;
	int cnt = 0;
	while (temp->Next)
	{
		cnt++;
		temp = temp->Next;
		if (temp->Data == i) break;
	}
	if (temp->Data == i) return cnt;
	else return ERROR;
}
bool Insert(List L, int i, ElementType X)
{
	int cnt = 1;
	List temp = L;
	if (i < 1) return false;
	else 
	{
		if (cnt == i)
		{
			List t = (List)malloc(sizeof(struct LNode));
			t->Data = X;
			t->Next = temp->Next;
			temp->Next = t;
			return true;
		}
		else
		{
			while (temp->Next)
			{
				cnt++;
				temp = temp->Next;
				if (cnt == i) break;
			}
			if (cnt == i)
			{
				List t = (List)malloc(sizeof(struct LNode));
				t->Data = X;
				t->Next = temp->Next;
				temp->Next = t;
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}
bool Delete(List L, int i)
{
	int cnt = 0;
	List temp = L;
	if (i < 1) return false;
	else
	{
		while (temp->Next)
		{
			cnt++;
			if (cnt == i) break;
			temp = temp->Next;
		}
		if (cnt == i)
		{
			Position t = temp->Next;
			temp->Next = t->Next;
			free(t);
			return true;
		}
		else return false;
	}
}

int main()
{
	List L = InitList();
	for (int i = 1; i <= 10; i++)
	{
		Insert(L, i, i);
	}
	Position t = L;
	while (t->Next)
	{
		cout << t->Next->Data << " ";
		t = t->Next;
	}
	cout << endl;
	for (int i = 2; i <= 8; i += 2)
	{
		cout << Delete(L, i) << " ";
	}
	cout << endl;
	t = L;
	while (t->Next)
	{
		cout << t->Next->Data << " ";
		t = t->Next;
	}
	cout << endl << "3处于第几位: " << Find(L, 3) << " " << "第3位是什么：" << FindKth(3, L) << endl;
	return 0;
}