// DoTheG.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>

using namespace std;

// A�� ��ü ����(0�� ��, 1�� ��)
// Size�� �� �δ��� ���� ũ�⸦ ������ �迭
// cnt�� �� �δ��� ���� ���� ������ ����.
int n, A[101][101], cnt, Size[101];

// ���� ������ ������� üũ
bool safe(int a, int b)
{
	return (0 <= a && a < n) && (0 <= b && b < n);
}

// sort�� �� operator
bool cmp(int a, int b)
{
	return a > b;
}

// dfs ����
void dfs(int a, int b, int c)
{
	// c�� �δ��� �ѹ���
	A[a][b] = c;

	// ���� �˻�
	if (safe(a + 1, b) && A[a + 1][b] == 1)
		dfs(a + 1, b, c);

	// ���� �˻�
	if (safe(a - 1, b) && A[a - 1][b] == 1)
		dfs(a - 1, b, c);

	// �� �˻�
	if (safe(a, b - 1) && A[a][b - 1] == 1)
		dfs(a, b - 1, c);

	// �Ʒ� �˻�
	if (safe(a, b + 1) && A[a][b + 1] == 1)
		dfs(a, b + 1, c);
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
				dfs(i, j, cnt + 1);
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
	//cin >> n;

	//for (int i = 0; i < n; ++i)
	//{
	//	for (int j = 0; j < n; ++j)
	//	{
	//		cin >> A[i][j];
	//	}
	//}

	n = 7;

	char* str = "0110100011010111101010000111010000001111100111000";

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int index = i * n + j;

			// char -> int
			int input = str[index] - '0';

			A[i][j] = input;
		}
	}
}

void output()
{
	cout << n << endl;

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

