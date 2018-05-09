#include <iostream>
using namespace std;

void PrintStar(int iNum)
{
	if (iNum == 0)
		return;

	cout << "*";

	int iCount = iNum - 1;
	PrintStar(iCount);
}

void Star(int iNum, int iMax)
{
	if (iNum == iMax + 1)
		return;

	PrintStar(iNum);
	cout << endl;
	Star(iNum + 1, iMax);
}

int main()
{
	int iNum;
	cin >> iNum;
	Star(1, iNum);

	return 0;
}
