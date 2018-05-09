#include <iostream>
using namespace std;

void 	function1(int iInput)
{
	if (iInput == 1)
	{ 
		cout << iInput;
		return;
	}

	int iValue;

	if (iInput % 2 == 1)
		iValue = 3 * iInput + 1;
	else
		iValue = iInput / 2;

	cout << iInput << endl;

	function1(iValue);
}

int main()
{
	int iInput;
	cin >> iInput;
	function1(iInput);

    return 0;
}
