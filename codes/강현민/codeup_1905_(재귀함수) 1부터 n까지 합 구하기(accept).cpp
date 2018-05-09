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

void function3(int iNum, int iCount, int iCal)
{
	if (iCount > iNum)
	{
		cout << iCal;
		return;
	}
		
	
	iCal = iCal + iCount;
	++iCount;
	function3(iNum, iCount, iCal);


}

int main()
{
	int iNumber = 0;
	cin >> iNumber;

	function3(iNumber, 1, 0);
	/*int iNumber = 0;
	cin >> iNumber;

	function(iNumber);*/

    return 0;
}




