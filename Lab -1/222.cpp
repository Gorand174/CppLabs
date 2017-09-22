#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float x, y;
	cout << "¬ведите значение x, а затем y: ";
		cin >> x >> y;
		if (x < 0 && y < 0)
		{
			x = abs(x), y = abs(y);
		}
		else
		{
			if ((x < 0) || (y < 0))
			{
				x = x + 0.5, y = y + 0.5;
			}
			else
				{
				if (((x >= 0) && (2 < x < 0.5)) && ((y >= 0) && (2 < y < 0.5)))
					{
					x = x / 10, y = y / 10;
				}
				else x = x, y = y;
			}

		}
			cout << x << " " << y;

		system("pause");
		return 0;
}


