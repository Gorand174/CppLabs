// ��� ������ ����� ����� ����������� n.
// ��� �������� ������� � ������� ��������, 
// �������������� ������� ������������� ��������,
// �������� �� ������������.

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int x;
	cout << "������� ����������� �������, � ����� ��� ��������: ";
	cin >> x;	// �������� ����������� �������

	int max, maxi = 0;
	int *a = new int[x];	// �������� ������������ ������ � ���� 

	for (int i = 0; i < x; i++)
	{
		cin >> a[i];	// �������� ����������� ���������� �������� ���������

		if (i == 0)
			max = a[i];	// 0-������� ����������� ������������ ���������

		if (a[i] > max)	// �����, ���� �������� ����������� ��������� ������ �������� ��������,
		{				
			max = a[i]; // ����� �������� ����������� �������������
			maxi = i;	// � ����� ������ �������� ������������ ��� ������������ �����
		}
	}

	for (int i = 0; i < maxi; i++)
	{
		if (i % 2 == 0)
			a[i] *= max;	// �������� ��� �������� � ������� �������� �� ������������ �������� ��������
		cout << a[i] << " ";
	}

	system("pause");
	delete a;
	return 0;
}