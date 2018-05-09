#include <vector>
#include <iostream>
using namespace std;

bool	chk[7][7];
int		map[7][7];

int iCount;
int cnt;

// i = y
// j = x
void		fnk(int i, int j, int value)
{
	if (i < 0 || i > 6 || j < 0 || j > 6 || chk[i][j] == true || value != map[i][j])
		return;

	cnt++;
	chk[i][j] = true;

	fnk(i, j + 1, value);
	fnk(i + 1, j, value);
	fnk(i, j - 1, value);
	fnk(i - 1, j, value);
}

int main()
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; ++j)
		{
			cin >> map[i][j];
		}
	}	

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; ++j)
		{
			cnt = 0;
			fnk(i, j, map[i][j]);

			if (cnt >= 3)
				++iCount;
		}
	}


	cout << iCount << endl;
	

	return 0;
}
