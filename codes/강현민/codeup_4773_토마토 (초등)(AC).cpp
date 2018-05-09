
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct _tagBox
{
	int x, y, z;
	int iValue;
}BOX, *LPBOX;

int	SearchTomato(vector<BOX>& vecBox, queue<BOX>& qBox, int M, int N, int H)
{
	int iCount = 0;

	while (!qBox.empty())
	{
		int iSize = qBox.size();

		for (int i = 0; i < iSize; i++)
		{
			BOX box = qBox.front();
			qBox.pop();

			int iIndexL = (M * box.y + box.x - 1) + (M * N * box.z);
			int iIndexR = (M * box.y + box.x + 1) + (M * N * box.z);

			int iIndexU = (M * (box.y - 1) + box.x) + (M * N * box.z);
			int iIndexD = (M * (box.y + 1) + box.x) + (M * N * box.z);

			int iIndexT = (M * box.y + box.x) + (M * N * (box.z + 1));
			int iIndexB = (M * box.y + box.x) + (M * N * (box.z - 1));

			if (iIndexL >= 0 && iIndexL < vecBox.size() && box.x - 1 >= 0 && box.x - 1 < M)
			{
				if (vecBox[iIndexL].iValue == 0)
				{
					vecBox[iIndexL].iValue = 1;
					qBox.push(vecBox[iIndexL]);
				}
			}

			if (iIndexR >= 0 && iIndexR < vecBox.size() && box.x + 1 >= 0 && box.x + 1 < M)
			{
				if (vecBox[iIndexR].iValue == 0)
				{
					vecBox[iIndexR].iValue = 1;
					qBox.push(vecBox[iIndexR]);
				}
			}

			if (iIndexD >= 0 && iIndexD < vecBox.size() && box.y + 1 >= 0 && box.y + 1 < N)
			{
				if (vecBox[iIndexD].iValue == 0)
				{
					vecBox[iIndexD].iValue = 1;
					qBox.push(vecBox[iIndexD]);
				}
			}

			if (iIndexU >= 0 && iIndexU < vecBox.size() && box.y - 1 >= 0 && box.y - 1 < N)
			{
				if (vecBox[iIndexU].iValue == 0)
				{
					vecBox[iIndexU].iValue = 1;
					qBox.push(vecBox[iIndexU]);
				}
			}

			if (iIndexB >= 0 && iIndexB < vecBox.size() && box.z - 1 >= 0 && box.z - 1 < H)
			{
				if (vecBox[iIndexB].iValue == 0)
				{
					vecBox[iIndexB].iValue = 1;
					qBox.push(vecBox[iIndexB]);
				}
			}

			if (iIndexT >= 0 && iIndexT < vecBox.size() && box.z + 1 >= 0 && box.z + 1 < H)
			{
				if (vecBox[iIndexT].iValue == 0)
				{
					vecBox[iIndexT].iValue = 1;
					qBox.push(vecBox[iIndexT]);
				}
			}
		}

		++iCount;
	}

	return iCount;
}

int main()
{
	vector<BOX>	vecBox;
	queue<BOX>	qBox;

	int iDate = 0;
	int M, N, H;

	cin >> M >> N >> H;

	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			for (int k = 0; k < M; ++k)
			{
				int iValue;
				BOX box;

				box.x = k;
				box.y = j;
				box.z = i;

				cin >> iValue;

				box.iValue = iValue;

				if (box.iValue == 1)
				{
					qBox.push(box);
				}

				vecBox.push_back(box);
			}
		}
	}

	int iCount = SearchTomato(vecBox, qBox, M, N, H);

	for (unsigned int i = 0; i < vecBox.size(); i++)
	{
		if (vecBox[i].iValue == 0)
		{
			cout << "-1" << endl;
			return 0;
		}
	}

	cout << iCount - 1 << endl;

	return 0;
}
