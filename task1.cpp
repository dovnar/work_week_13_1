#include <iostream>
#include <iostream>
#include <time.h>

using namespace std;

int* createRundomArray(int*, int);
void printArray(int*, int);
int main()
{
	setlocale(LC_ALL, "rus");
	int itemCount;
	do
	{
		cout << "введите количество элементов\n для выхода нажмите 0\n= ";
		cin >> itemCount;
		int* arr = new int[itemCount];
		createRundomArray(arr, itemCount);
		printArray(arr, itemCount);
		delete[] arr;
	} while (itemCount != 0);
	
}

int* createRundomArray(int* arr, int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10000 + 1000000;
	}
	return arr;
}
void printArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (i % 10 == 0)
		{
			cout << endl;
		}
		cout << arr[i] << " ";
	}
	return;
}