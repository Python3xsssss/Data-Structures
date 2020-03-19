#include "unsorted_table.h"
#include "Polynomials.h"
#include <conio.h>

using std::cin;

void main()
{
	string str1;

	cout << "Enter the polynomial 1: " << endl;
	getline(cin, str1);
	Polynomial pol1(str1);
	cout << "Enter the polynomial 2: " << endl;
	getline(cin, str1);
	Polynomial pol2(str1);
	cout << "Enter the polynomial 3: " << endl;
	getline(cin, str1);
	Polynomial pol3(str1);
	cout << "Enter the polynomial 4: " << endl;
	getline(cin, str1);
	Polynomial pol4(str1);

	UnsortedTable<Polynomial> table(3);

	table.Insert("123", pol1);
	table.Insert("124", pol2);
	table.Insert("125", pol3);

	cout << table << endl;
	cout << endl << endl;

	table.Insert("126", pol4);
	
	cout << table << endl;

	_getch();
}