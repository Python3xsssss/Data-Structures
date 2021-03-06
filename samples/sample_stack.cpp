#include <iostream>
#include <string>
#include "stack_on_array.h"
#include <conio.h>

using namespace std;

int main(int argc, char* argv[])
{
	Stack<char> st;
	string tmp;
	if (argc > 1)
		tmp = argv[1];
	else
	{
		cout << "Enter the formula" << endl;
		cin >> tmp;
	}
	bool flag = true;
	size_t i = 0;
	while ((tmp[i] != '\0') && flag)
	{
		if ((tmp[i] == '(') || (tmp[i] == '{') || (tmp[i] == '['))
			st.Push(tmp[i]);
		else if (st.GetSize() > 0)
		{
			char comp = st.Top();
			if ((tmp[i] == ')') && (comp == '(') || (tmp[i] == '}') && (comp == '{') || (tmp[i] == ']') && (comp == '['))
				st.Pop();
			else
				flag = false;
		}
		else
			flag = false;
			
		i++;
	}
	if (st.GetSize() > 0)
		flag = false;
	cout << endl << flag << endl;
	_getch();
}