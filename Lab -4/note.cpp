#define _CRT_SECURE_NO_WARNINGS		
#include <iostream>			
#include <cstdlib>

using namespace std;

struct note
{
	char surname[99]; //хотел использовать readString(), но не понял, как его вставить
	char name[99];    //к тому же для двух char
	char number[11];
	unsigned short bd[3];
}

int main()
{
	note* X = new note[8];
	int a = 0;
	for (int i = 0; i < 8; i++)

	{
		cout << "Введите фамилию сотрудника: " << endl;
		cout << "Для окончания ввода данных введите 0" << endl;
		cin >> X[i].surname;
		if (X[i].surname[0] == '0')
		{
			break;
		}
		else 
		{
			a = a + 1;
			cout << "Введите имя сотрудника: " << endl;
			cin >> X[i].name;
			cout << "Введите номер телефона (без 8 и +7): ";
			cin >> X[i].number;
			cout << "Введите дату рождения (ДД/ММ/ГГГГ): ";
			cin >> X[i].bd[0];
			cin >> X[i].bd[1];
			cin >> X[i].bd[2];
		}
	}

	for (int i = 0; i < a - 1; i++)
	{
		if (X[i].name[0] > X[i + 1].name[0])
		{
			swap(X[i], X[i + 1]);
		}
	}

	char* readString()
	{
		char buf[255];
		cin.get(buf, 255);
		char* str = new char[strlen(buf)];
		strcpy(str, buf);
		return str;
	}

	for (int i = 0; i < a; i++)
		cout << X[i].name << " " << X[i].number << " " << X[i].bd << endl;
	char* family = readString();
	cout << "Введите фамилию сотрудника: ";
	cin >> family;
	bool check = false;
	for (int i = 0; i < a; i++)
	{
		if (*X[i].surname == *family)
		{
			check = true;
			cout << X[i].name << ": " << X[i].number << endl;
		}

	}
	if (!check)
		cout << "Сотрудник не найден, повторите попытку";
	delete[]X;
	system("pause");
}
