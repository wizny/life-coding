// DoTheG.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <algorithm>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

// A는 전체 지도(0은 땅, 1은 굴)
// Size는 각 두더지 굴의 크기를 저장할 배열
// cnt는 총 두더지 굴의 수를 저장할 변수.
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

// 지도 영역을 벗어나는지 체크
bool safe(int a, int b)
{
	return (0 <= a && a < n) && (0 <= b && b < n);
}

// sort에 들어갈 function
bool cmp(int a, int b)
{
	return a > b;
}

// dfs 진행
//void dfs(int a, int b, int c)
//{
//	// c는 두더지 넘버링
//	A[a][b] = c;
//
//	// 우측 검사
//	if (safe(a + 1, b) && A[a + 1][b] == 1)
//		dfs(a + 1, b, c);
//
//	// 좌측 검사
//	if (safe(a - 1, b) && A[a - 1][b] == 1)
//		dfs(a - 1, b, c);
//
//	// 위 검사
//	if (safe(a, b - 1) && A[a][b - 1] == 1)
//		dfs(a, b - 1, c);
//
//	// 아래 검사
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
	// 모든 지도에 대해 검사
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			// 지도에 원소가 1이면 아직 주인 없는 두더지 굴
			if (A[i][j] == 1)
			{
				// 두더지의 수를 하나 증가
				cnt++;
				// dfs를 실행
				//dfs(i, j, cnt + 1);
				bfs(i, j, cnt + 1);
			}
		}
	}

	// 모든 지도에 대해 검사
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			// sorting을 위해서 배열의 2번부터 시작한 두더지굴의 갯수를 앞으로 땡겨준다.
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

	// 공백없이받을때
	// 그런데 문제엔 공백이 포함
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

