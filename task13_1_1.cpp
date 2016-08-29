#include <iostream>
#include <stdarg.h>

using namespace std;

int max(int n, ...);

int main()
{
	int number[5];
	for (int i = 0; i < 5; i++)
	{
		cout << "number " << i + 1 << ": ";
		cin >> number[i];
	}
	cout << "\n" << max(5, number[0], number[1], number[2], number[3], number[4]) << endl;
}

int max(int n, ...)
{
	int maxValue = -1000;
	va_list list;
	va_start(list, n);
	for (int i = 0; i < n; i++)
	{
		int k = va_arg(list, int);
		if (k < 0)
		{
			cout << k << " ";
			if (k > maxValue)
			{
				maxValue = k;
			}
		}
	}
	va_end(list);
	return maxValue;
}