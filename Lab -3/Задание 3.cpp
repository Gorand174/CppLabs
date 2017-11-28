//3. В текстовом файле INPUT.TXT записаны целые числа через пробел, возможно, в несколько строк.
//За один просмотр файла сформировать список этих чисел. Проверить наличие в списке заданного числа.
//Результат (ЕСТЬ или НЕТ) занести в текстовый файл OUTPUT.TXT.

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream output("OUTPUT.txt");
	ifstream input("INPUT.txt");

	int n = (int)1e6;
	int *a = new int[n];
	int y = 0;

	while (input >> a[y])

	{
		if (a[y] == ' ')
			continue;
		y++;
	}

	int need;
	cout << "Какое число необходимо обнаружить? ";
	cin >> need;

	bool v = false;
	for (int i = 0; i<y; i++)
	{
		if (a[i] == need)
		{
			v = true;
			break;
		}
	}

	if (v == true)
		output << "ЕСТЬ";
	else
		output << "НЕТ";
	cout << "Результат в файле OUTPUT.TXT";

	output.close();
	input.close();
	
	system("pause");
	delete[]a;
	return 0;
}
