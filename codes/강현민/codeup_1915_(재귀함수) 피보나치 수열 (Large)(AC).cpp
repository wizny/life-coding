// ConsoleApplication2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include <iostream>

using namespace std;

void function(int iNum)
{
	if (iNum < 1)
		return;

	cout << iNum << endl;

	--iNum;
	function(iNum);
}

//void function2(int iStart, int iEnd)
//{
//	if (iStart > iEnd)
//		return;
//
//	if (iStart % 2 == 1)
//		cout << iStart << " ";
//
//	++iStart;
//	function2(iStart, iEnd);
//}

//void function3(int iNum, int iCount, int iCal)
//{
//	if (iCount > iNum)
//	{
//		cout << iCal;
//		return;
//	}
//	
//	iCal = iCal + iCount;
//	++iCount;
//	function3(iNum, iCount, iCal);
//}

//void function3(int iNum, int iResult)
//{
//	if (iNum < 1)
//	{
//		cout << iResult;
//		return;
//	}
//
//	iResult = iResult * iNum;
//	--iNum;
//	function3(iNum, iResult);
//}

int function3(int iN)
{
	if (iN == 1 || iN == 2)
		return 1;

	return function3(iN - 1) + function3(iN - 2);
}

int main()
{
	int iNumber = 0;
	cin >> iNumber;

	
	cout << function3(iNumber);
	/*int iNumber = 0;
	cin >> iNumber;

	function(iNumber);*/

    return 0;
}




