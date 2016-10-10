#include <iostream>
using namespace std;

void getCar(int const stringSize, int const countCar, struct CarInfo*& carInfo);
void printCarInfo(struct CarInfo* carInfo, int const countCar);
int sortCar(struct CarInfo carInfo1, struct CarInfo carInfo2);
struct CarInfo
{
	char* Make;
	char* Model;
	int YearOf;
	int Weight;
};


void main()
{
	int stringSize = 256;
	int countCar;
	cout << "enter count car: ";
	cin >> countCar;
	struct CarInfo* carInfo = new CarInfo[countCar];
	
	for (int i = 0; i < countCar; i++)
	{
		carInfo[i].Make = new char[stringSize];
		carInfo[i].Model = new char[stringSize];
	}
	getCar(stringSize, countCar, carInfo);
	printCarInfo(carInfo, countCar);

	for (int i = 0; i < countCar; i++)
	{
		delete[] carInfo[i].Make;
		delete[] carInfo[i].Model;
	}
	delete[] carInfo;
}

void getCar(int const stringSize, int const countCar, struct CarInfo*& carInfo)
{
	for (int i = 0; i < countCar; i++)
	{
		fflush(stdin);
		cout << "car "<< i+1 << ":\nenter make car: ";
		cin.getline(carInfo[i].Make, stringSize);
		cout << "enter model car: ";
		cin.getline(carInfo[i].Model, stringSize);
		cout << "enter year of car: ";
		cin >> carInfo[i].YearOf;
		cout << "enter weight car: ";
		cin >> carInfo[i].Weight;
	}
	
}

void printCarInfo(struct CarInfo* carInfo, int const countCar)
{
	cout << "| # \t| make car \t| model car \t| year of car \t| weight car \t|\n";
	for (int i = 0; i < countCar; i++)
	{
		cout << "_________________________________________________________________________\n";
		cout << "| " << i << " \t| " << carInfo[i].Make;
		if (strlen(carInfo[i].Make) < 6)
		{
			cout << " \t ";
		}
		cout << " \t| " << carInfo[i].Model;
		if (strlen(carInfo[i].Model) < 6)
		{
			cout << " \t ";
		}
			cout << " \t| " << carInfo[i].YearOf << " \t\t| " << carInfo[i].Weight << "\t\t|" << endl;
	}
	
}

int sortCar(struct CarInfo carInfo1, struct CarInfo carInfo2)
{
	if (carInfo1.YearOf > carInfo2.YearOf)
	{
		return 1;
	}
	else if (carInfo1.YearOf < carInfo2.YearOf)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}