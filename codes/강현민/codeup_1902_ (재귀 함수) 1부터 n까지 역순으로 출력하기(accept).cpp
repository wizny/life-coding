// ConsoleApplication2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include <iostream>

using namespace std;

void function(int iNum);

int main()
{
	int iNumber = 0;
	cin >> iNumber;

	function(iNumber);

    return 0;
}

void function(int iNum)
{
	if (iNum >= 1 && iNum <= 200)
	{
		if (iNum < 1)
			return;

		cout << iNum << endl;

		--iNum;
		function(iNum);
	}
}


