#include "unsorted_table.h"
#include "sorted_table.h"
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

	SortedTable<Polynomial> sortable(3);

	sortable.Insert("120", pol1);
	sortable.Insert("128", pol2);
	sortable.Insert("121", pol3);
	sortable.Insert("119", pol4);
	sortable.Insert("130", pol4);
	sortable.Insert("126", pol4);
	sortable.Insert("125", pol4);
	sortable.Insert("124", pol4);

	sortable.Insert("1", pol4);
	
	cout << sortable << endl;

	sortable.Delete("120");
	cout << sortable << endl;
	sortable.Delete("130");
	cout << sortable << endl;
	sortable.Delete("1");
	cout << sortable << endl;
	sortable.Insert("1", pol4);
	sortable.Insert("130", pol4);
	sortable.Delete("1");
	cout << sortable << endl;

	_getch();
}