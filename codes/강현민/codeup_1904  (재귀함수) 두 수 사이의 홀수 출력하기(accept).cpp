// ConsoleApplication2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include <iostream>

using namespace std;



void function2(int iStart, int iEnd)
{
	if (iStart > iEnd)
		return;

	if (iStart % 2 == 1)
		cout << iStart << " ";

	++iStart;
	function2(iStart, iEnd);
}

int main()
{
	int iStart = 0;
	int iEnd = 0;
	cin >> iStart;
	cin >> iEnd;

	function2(iStart, iEnd);
	/*int iNumber = 0;
	cin >> iNumber;

	function(iNumber);*/

    return 0;
}




