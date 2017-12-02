#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>


using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	ifstream input("INPUT.txt");
	if (!input)
	{
		cout << "Файл INPUT.txt не найден";
	}

	ofstream output("OUTPUT.txt");

	int s = 0, highest_s = 0, b = 0, bb = 0;
	char buf[300];
	char *name, *surname, *patronymic, *nname, *nsurname, *npatronymic, *salary, *year;

	while (!input.eof())
	{
		input.getline(buf, 300);
		name = strtok(NULL, ";");
		surname = strtok(NULL, ";");
		patronymic = strtok(NULL, ";");
		year = strtok(NULL, ";");
		salary = strtok(NULL, ";");

		int *A = new char[256];

		b = atoi(year);
		s = atoi(salary);

		if ((2017 - b) < 35)
		{
			swap(s, highest_s)
			nname = name;
			nsurname = surname;
			npatronymic = patronymic;
			bb = b;
			highest_s = s;
		}	
		;
	}
	output << nname << " " << nsurname << " " << npatronymic << '\n' << "Возраст: " << bb;

	input.close();
	output.close();

	system("pause");
	delete[]A;
	return 0;
}
