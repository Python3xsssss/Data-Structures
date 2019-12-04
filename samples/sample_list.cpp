#include <string>
#include "List.h"
#include <conio.h>

using std::cout;
using std::endl;

int main()
{
	List<int> st;
	for (int i = 0; i < 10; i++)
		st.Push_top(i);
	cout << "List: ";
	st.Print();
	if (st.IsLooped())
		cout << "There's a loop in the list." << endl;
	else
		cout << "There's no loop in the list." << endl;
	st.Reverse();
	cout << "Reversed list: ";
	st.Print();

	List<int> ls(7, 2);
	cout << endl <<"Created new list. Is there a loop?" << endl;
	if (ls.IsLooped())
		cout << "Yes, there's a loop." << endl;
	else
		cout << "No, there's no loop." << endl;
	_getch();
}