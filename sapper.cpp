#include <iostream>
#include <time.h>

void initializeFieldBack(int** fieldBack, int size);
void printFieldAll(int** fieldBack, char** fieldFront, int size);

int main()
{
	int const size = 10;
	int** fieldBack = new int*[size];
	for (int i = 0; i < size; i++)
	{
		*(fieldBack + i) = new int[size];
		memset(*(fieldBack + i), 0, sizeof(int)* size);
	}
	char** fieldFront = new char*[size];
	for (int i = 0; i < size; i++)
	{
		*(fieldFront + i) = new char[size] {char(254), char(254), char(254), char(254), char(254), char(254), char(254), char(254), char(254), char(254)};
	}

	initializeFieldBack(fieldBack, size);
	printFieldAll(fieldBack, fieldFront, size);

	for (int i = 0; i < size; i++)					//delete back field
	{
		delete[] * (fieldBack + i);
	}
	delete[] fieldBack;								//delete back field

	for (int i = 0; i < size; i++)					//delete front field
	{
		delete[] * (fieldFront + i);
	}
	delete[] fieldFront;									//delete front field
}

void initializeFieldBack(int** fieldBack, int size)			//{char 253, int 9 bomb} {char 149, int 0 pusto} {char 254 neotmechenaia oblost'}
{
	int vertical, horizontal;
	int count = 0;
	srand(time(NULL));
	do									//заполнение бомбами
	{
		vertical = rand() % 10;
		horizontal = rand() % 10;
		if (fieldBack[vertical][horizontal] != 9)
		{
			fieldBack[vertical][horizontal] = 9;
			count++;
		}
	} while (count < 10);				//заполнение бомбами

	for (vertical = 0; vertical < size; vertical++)					//инитиализатия числами
	{
		for (horizontal = 0; horizontal < size; horizontal++)
		{
			if (fieldBack[vertical][horizontal] == 9)
			{
				for (int v = -1; v < 2; v++)
				{
					for (int h = -1; h < 2; h++)
					{
						if (v != 0 || h != 0)
						{
							if (((vertical + v) >= 0 && (vertical + v) < 10) &&
								((horizontal + h) >= 0 && (horizontal + h) < 10))
							{
								if (fieldBack[vertical + v][horizontal + h] != 9)
								{
									fieldBack[vertical + v][horizontal + h]++;
								}
							}
						}
					}
				}
			}
		}
	}																//инитиализатия числами
}

void printFieldAll(int** fieldBack, char** fieldFront, int size)		//{char 253, int 9 bomb} {char 149, int 0 pusto} {char 254 neotmechenaia oblost'}
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			std::cout << fieldBack[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "select cell in field" << std::endl;
	int game = 1;
	do
	{
		int vertical, horizontal;
		for (vertical = 0; vertical < size; vertical++)
		{
			for (horizontal = 0; horizontal < size; horizontal++)
			{
				std::cout << fieldFront[vertical][horizontal] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << "enter vertical: ";
		std::cin >> vertical;
		std::cout << "enter horizontal: ";
		std::cin >> horizontal;
		int value = fieldBack[vertical][horizontal];
		if (value == 9)
		{
			fieldFront[vertical][horizontal] = char(253);
			std::cout << "game over" << std::endl;
			game = 0;
		}
		else if (value == 0)
		{
			fieldFront[vertical][horizontal] = char(249);
		}
		else
		{
			fieldFront[vertical][horizontal] = char(value + 48);
		}
	} while (game != 0);
}
