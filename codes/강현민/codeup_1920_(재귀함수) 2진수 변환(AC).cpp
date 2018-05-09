#include <iostream>
#include <vector>
using namespace std;

vector<int>		vecNum;

void 	function1(int iInput)
{
	if (iInput == 0 || iInput == 1)
	{ 
		vecNum.push_back(iInput);
		return;
	}
		

	int iValue = iInput / 2;
	int iValue2 = iInput % 2;

	vecNum.push_back(iValue2);
	function1(iValue);
}

void 	function2(int iCount)
{
	if (iCount == 0)
		return;

	--iCount;
	cout << vecNum[iCount];
	function2(iCount);
}

int main()
{
	int iInput;
	cin >> iInput;
	function1(iInput);
	function2(vecNum.size());

    return 0;
}
