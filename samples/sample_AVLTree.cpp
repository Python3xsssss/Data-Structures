#include "AVLTree.h"
#include <conio.h>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main()
{
	AVLTree<int> tree;
	for (size_t i = 0; i < 10; i++)
	{
		size_t key = i + 100;
		tree.Insert(i, key);
	}

	cout << tree.Find(101) << endl;
	cout << tree.Find(102) << endl;

	tree.Delete(101);
	cout << "Deleted" << endl;
	tree.Clean();
	//cout << tree.Find(102) << endl;


	_getch();
}