/**************************************************************
Problem: 1106
User: wizny8206
Language: C++
Result: Success
Time:1 ms
Memory:1836 kb
****************************************************************/


#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int jump[8][2] = { { -2, 1 },{ -2,-1 },{ -1, 2 },{ -1, -2 },{ 1, 2 },{ 1, -2 },{ 2, 1 },{ 2, -1 } };

struct  rc
{
	int r, c;
	int status;
};

int malR, malC;
int jolR, jolC;
int R, C;

int malpan[110][110];
int visited[110][110];

bool outside(int r, int c)
{
	return r < 1 || r > R || c < 1 || c > C;
}

int     solve()
{
	queue<rc> q;
	q.push(rc{ malR, malC });
	malpan[malR][malC] = 0;


	while (!q.empty())
	{
		rc p = q.front(); q.pop();

		if (p.r == jolR && p.c == jolC)
			return malpan[jolR][jolC];

		for (int i = 0; i < 8; i++)
		{
			int r2 = p.r + jump[i][0];
			int c2 = p.c + jump[i][1];

			if (outside(r2, c2))
				continue;

			if (visited[r2][c2] == 0)
			{
				visited[r2][c2] = 1;
				q.push(rc{ r2,c2 });
				malpan[r2][c2] = malpan[p.r][p.c] + 1;
			}
		}
	}
}

int main()
{
	cin >> R >> C;

	cin >> malR >> malC >> jolR >> jolC;

	cout << solve() << endl;

	return 0;
}