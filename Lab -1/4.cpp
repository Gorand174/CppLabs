#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double who = 0;
	double doc = 0;
	while (1)
	{
		double tor;
		cout << "���� �����/'0' ��� ����������: ";
		cin >> tor;
		if (tor == 0)
			break;
		if (tor > 0)
		{
			who += tor;
			doc++;
		}
	}
	double i;
	i = who / doc;
	cout << i << " ";

	system("pause");
	return 0;
}