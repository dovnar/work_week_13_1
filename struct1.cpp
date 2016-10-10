#include <iostream>
using namespace std;

void getCar(int stringSize, struct CarInfo& carInfo);
void printCarInfo(struct CarInfo carInfo);
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
	struct CarInfo carInfo1;
	struct CarInfo carInfo2;
	int stringSize = 256;
	carInfo1.Make = new char[stringSize];
	carInfo1.Model = new char[stringSize];
	carInfo2.Make = new char[stringSize];
	carInfo2.Model = new char[stringSize];

	getCar(stringSize, carInfo1);
	getCar(stringSize, carInfo2);

	int resultSort = sortCar(carInfo1, carInfo2);
	if (resultSort > 0)
	{
		printCarInfo(carInfo1);
		printCarInfo(carInfo2);
	}
	else if (resultSort < 0)
	{
		printCarInfo(carInfo2);
		printCarInfo(carInfo1);
	}
	else
	{
		cout << "cars are years";
		printCarInfo(carInfo1);
		printCarInfo(carInfo2);
	}
	

	delete[] carInfo1.Make;
	delete[] carInfo1.Model;
	delete[] carInfo2.Make;
	delete[] carInfo2.Model;
}

void getCar(int stringSize, struct CarInfo& carInfo)
{
	fflush(stdin);
	cout << "enter make car: ";
	cin.getline(carInfo.Make, stringSize);
	cout << "enter model car: ";
	cin.getline(carInfo.Model, stringSize);
	cout << "enter year of car: ";
	cin >> carInfo.YearOf;
	cout << "enter weight car: ";
	cin >> carInfo.Weight;
}

void printCarInfo(struct CarInfo carInfo)
{
	cout << "make car: " << carInfo.Make << endl << "model car: " << carInfo.Model << endl
		<< "year of car: " << carInfo.YearOf << endl << "weight car: " << carInfo.Weight << endl;
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