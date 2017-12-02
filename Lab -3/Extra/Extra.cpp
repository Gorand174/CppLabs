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

		b = atoi(year);
		s = atoi(salary);

		if ((s > highest_s) && (2017 - b) < 35)
		{
		nname = name;
		nsurname = surname;
		npatronymic = patronymic;
		bb = b;
		highest_s = s;
		}	
	}

	int r = 0;
	for (int i = 0; i < r - 1; i++)
	{

	}

	output << nname << " " << nsurname << " " << npatronymic << '\n' << "Ахаха: " << bb;
	input.close();
	output.close();
}