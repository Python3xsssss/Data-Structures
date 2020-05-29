#include "unsorted_table.h"
#include "sorted_table.h"
#include "hash_table.h"
#include "Polynomials.h"
#include <conio.h>

using std::cin;

void main()
{
	string str1;
	size_t amount = 3;

	HashTable<Polynomial> hash(amount * amount);

	for (size_t i = 0; i < amount; i++)
	{
		cout << "Enter the polynomial " << i + 1 << ": " << endl;
		getline(cin, str1);
		Polynomial pol1(str1);
		char buf[256];
		itoa(i, buf, 10);
		string tmp = buf;
		string str = "10" + tmp;
		cout << "Id: " << str << endl;
		hash.Insert(str, pol1);
	}

	cout << hash.Find("101") << endl;
	cout << hash.Find("102") << endl;

	hash.Delete("101");
	cout << "Deleted" << endl;
	cout << hash.Find("101") << endl;

	_getch();
}