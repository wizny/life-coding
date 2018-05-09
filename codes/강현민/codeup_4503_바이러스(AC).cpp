#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<vector<int>>		adjList;
bool					vis[110];

int		fnk(int k)
{
	queue<int>	q; int count = 0;
	q.push(k);

	while (!q.empty())
	{
		int s = q.front(); q.pop();

		if (vis[s] == true)
			continue;

		vis[s] = true; count++;

		for (int j = 0; j < adjList[s].size(); ++j)
		{
			int e = adjList[s][j];

			if (vis[e] == false)
				q.push(e);
		}
	}

	return count;
}

int main()
{
	int v;
	cin >> v;
	adjList.resize(v + 1);

	int n;
	cin >> n;
	while (n-- > 0)
	{
		int s, e;

		cin >> s >> e;
		adjList[s].push_back(e);
		adjList[e].push_back(s);
	}

	n = fnk(1);
	
	cout << n - 1 << endl;

	return 0;
}


