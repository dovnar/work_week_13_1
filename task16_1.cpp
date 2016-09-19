#include <iostream>

int main()
{
	int const count{ 50 };
	char strhelp[]{"hello user, enter yuo is name: "};
	char str[count];
	char* prov;
	puts(strhelp);
	std::cin.getline(str, count);
	puts(str);
}