#include <iostream>
using namespace std;

int SuperSum(int k, int n)
{
	if (k == 0)
		return n;

	int iValue = 0;

	for (int i = 1; i <= n; ++i)
	{
		iValue += SuperSum(k - 1, i);
	}		

	return iValue;
}

int main()
{
	int k, n;
	while (scanf("%d %d", &k, &n) != EOF)
	{
		cout << SuperSum(k, n) << endl;
	}

	return 0;
}

