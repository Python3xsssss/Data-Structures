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
	st.Print();
	st.Insert(5, 22);
	st.Print();
	st.Push_bot(23);
	st.Print();
	st.Pop();
	st.Print();
	st.Delete(9);
	st.Print();
	cout << st.Top() << endl;
	_getch();
}