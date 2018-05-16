#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
//#include <Windows.h>
#include <map>
//using namespace std;

int n, ans, col[14], row[14], inc[100], dec[100];
std::vector<int*> vecResult;
std::multimap<long long, int*> mapResult;

void	Sorting(const std::vector<int*>& vecData)
{
	auto iter = mapResult.begin();
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 1; j < n + 1; ++j)
		{
			std::stringstream str;
			str << iter->second[j];
			std::cout << str.str().c_str() << " ";
		}
		std::cout << std::endl;
		++iter;
		int sdifj = 1;
	}
	




/*	std::vector<LONGLONG> vecSort;

	for (int i = 0; i < vecResult.size(); ++i)
	{
		LONGLONG value = 0;

		for (int j = 1; j < n + 1; ++j)
		{
			value += vecResult[i][j] * pow(10, n - j);
		}
		vecSort.push_back(value);
	}

	std::sort(vecSort.begin(), vecSort.end());

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < vecData.size(); ++j)
		{

		}

		std::stringstream str;
		str << vecSort[i];

		for (int j = 0; j < n; ++j)
		{
			std::cout << str.str().c_str()[j] << " ";
		}

		std::cout << std::endl;
	}*/	
}

void solve(int r)
{
	if (r > n)
	{
		// 마지막 행까지 다 퀸을 놓았으면 해를 추가.
		ans++;

		int* cpRow = new int[14];
		for (int i = 0; i < 14; ++i)
		{
			cpRow[i] = row[i];
		}

		long long value = 0;

		for (int j = 1; j < n + 1; ++j)
		{
			value += cpRow[j] * pow(10, n - j);
		}

		mapResult.insert(std::pair<long long, int*>(value, cpRow));

		//for (int i = 0; i < vecResult.size(); ++i)
		{
			
			//vecSort.push_back(value);
		}

		// 백트랙
		return;
	}

	// r행에 대해서 각 열에 놓기 시작
	for (int i = 1; i <= n; i++)
	{
		if (!col[i] && !inc[r + i] && !dec[n + (r - i) + 1])
		{
			// 열과 대각선 체크
			col[i] = inc[r + i] = dec[n + (r - i) + 1] = 1;
			row[r] = i;
			solve(r + 1);
			// 백트랙 후 흔적 제거
			col[i] = inc[r + i] = dec[n + (r - i) + 1] = 0;
			row[r] = 0;
		}
	}
}

int main()
{
	std::cin >> n;
	solve(1);
	Sorting(vecResult);
	std::cout << ans << std::endl;

    return 0;
}


