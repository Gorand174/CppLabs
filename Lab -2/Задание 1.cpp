#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cout << "¬ведите размерность массива, а затем его элементы: ";
	cin >> n;

	int *a = new int[n];

	int even, odd, result;
	even = 0;
	odd = 0;
	result = 1;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] % 2 == 0)
			even++;
		else
			odd++;
	}

	if (even == odd)
	{
		for (int i = 0; i < n; i++)
		{
			result *= a[i] + a[n - 1 - i];
		}

		cout << result; //выводитс€ только в случае, если even == odd
	}

	system("pause");
	delete[]a;
	return 0;
}