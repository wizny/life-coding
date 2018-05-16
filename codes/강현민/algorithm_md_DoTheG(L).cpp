// DoTheG.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <algorithm>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

// A�� ��ü ����(0�� ��, 1�� ��)
// Size�� �� �δ��� ���� ũ�⸦ ������ �迭
// cnt�� �� �δ��� ���� ���� ������ ����.
int n, A[101][101], cnt, Size[101];
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };

struct VERTEX 
{
	int a, b; 

	VERTEX(int a1, int b1)
	{
		a = a1;
		b = b1;
	}
};

// ���� ������ ������� üũ
bool safe(int a, int b)
{
	return (0 <= a && a < n) && (0 <= b && b < n);
}

// sort�� �� function
bool cmp(int a, int b)
{
	return a > b;
}

// dfs ����
//void dfs(int a, int b, int c)
//{
//	// c�� �δ��� �ѹ���
//	A[a][b] = c;
//
//	// ���� �˻�
//	if (safe(a + 1, b) && A[a + 1][b] == 1)
//		dfs(a + 1, b, c);
//
//	// ���� �˻�
//	if (safe(a - 1, b) && A[a - 1][b] == 1)
//		dfs(a - 1, b, c);
//
//	// �� �˻�
//	if (safe(a, b - 1) && A[a][b - 1] == 1)
//		dfs(a, b - 1, c);
//
//	// �Ʒ� �˻�
//	if (safe(a, b + 1) && A[a][b + 1] == 1)
//		dfs(a, b + 1, c);
//}
void bfs(int a, int b, int c)
{
	queue<VERTEX> Q;
	Q.push(VERTEX(a, b)), A[a][b] = c;

	while (!Q.empty())
	{
		VERTEX curr = Q.front(); Q.pop();
		for (int i = 0; i < 4; ++i)
		{
			if (safe(curr.a + dx[i], curr.b + dy[i]) && A[curr.a + dx[i]][curr.b + dy[i]] == 1)
			{
				A[curr.a + dx[i]][curr.b + dy[i]] = c;
				Q.push(VERTEX(curr.a + dx[i], curr.b + dy[i]));
			}
		}
	}
}

void solve()
{
	// ��� ������ ���� �˻�
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			// ������ ���Ұ� 1�̸� ���� ���� ���� �δ��� ��
			if (A[i][j] == 1)
			{
				// �δ����� ���� �ϳ� ����
				cnt++;
				// dfs�� ����
				//dfs(i, j, cnt + 1);
				bfs(i, j, cnt + 1);
			}
		}
	}

	// ��� ������ ���� �˻�
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			// sorting�� ���ؼ� �迭�� 2������ ������ �δ������� ������ ������ �����ش�.
			if (A[i][j])
			{
				Size[A[i][j] - 2]++;
			}
		}
	}

	// Sorting
	std::sort(Size, Size + cnt, cmp);
}

void input()
{
	cin >> n;
	char str[256];
	//string str;

	// ������̹�����
	// �׷��� ������ ������ ����
	//for (int i = 0; i < n; ++i)
	//{
	//	cin >> str;

	//	for (int j = 0; j < n; ++j)
	//	{
	//		A[i][j] = str[j] - '0';
	//	}

	//	int sdfjisdfji = 1;
	//}

	gets_s(str);
	for (int i = 0; i < n; ++i)
	{
		gets_s(str);

		for (int j = 0; j < n; ++j)
		{
			A[i][j] = str[j * 2] - '0';
		}
	}

	//n = 7;

	//char* str = "
	/*
	0 1 1 0 1 0 0
	0 1 1 0 1 0 1
	1 1 1 0 1 0 1
	0 0 0 0 1 1 1
	0 1 0 0 0 0 0
	0 1 1 1 1 1 0
	0 1 1 1 0 0 0
	";*/

	//char* str = "
	/*
	0110100
	0110101
	1110101
	0000111
	0100000
	0111110
	0111000
	";*/

	//for (int i = 0; i < n; ++i)
	//{
	//	for (int j = 0; j < n; ++j)
	//	{
	//		int index = i * n + j;

	//		// char -> int
	//		int input = str[index] - '0';

	//		A[i][j] = input;
	//	}
	//}
}

void output()
{
	cout << cnt << endl;

	for (int i = 0; i < cnt; ++i)
	{
		cout << Size[i] << endl;
	}
}

int main()
{
	input();
	solve();
	output();

    return 0;
}

