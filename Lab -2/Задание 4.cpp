#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cout << "Введите размерность квадратной матрицы, а затем все её элементы: ";
	cin >> n;

	int **x = new int*[n];
	int *y = new int[2 * n];


	for (int i = 0; i < n; i++)
	{
		x[i] = new int[n];
		for (int j = 0; j < n; j++)
			cin >> x[i][j];
	}


	int k = 0, sum;
	for (int i = n - 1; i > 0; i--)
	{
		sum = 0;
		for (int j = i; j < n; j++)
			sum += x[j][j - i];
		y[k++] = sum;
	}
	

	for (int i = 0; i < n; i++)
	{
		sum = 0;
		for (int j = i; j < n; j++)
			sum += x[j - i][j];
		y[k++] = sum;
	}

	cout << "Суммы по диагоналям: ";
	for (int i = 0; i < 2 * n - 1; i++)
		cout << y[i] << " ";

	system("pause");
	delete[]x;
	delete[]y;
	return 0;
}