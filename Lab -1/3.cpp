#include <iostream> // Среди двузначных чисел найти те, сумма квадратов цифр которых делится на 13.
using namespace std;

int main()
{
	int counter = 0;
	for (int i = 10; i <= 99; i++)
	{
		int twin = i % 10;
		int peaks = i / 10;
		int sum = twin*twin + peaks*peaks;
		if (sum % 13 == 0)
		{
			cout << counter << ": " << i << endl;
			counter++;
		}

	}
	system("pause");
	return 0;
}
