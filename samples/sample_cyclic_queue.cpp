#include "cyclic_queue.h"
#include <conio.h>
#include <cstdlib>
#include <ctime>
int main()
{
	srand(time(NULL));
	CQueue<int> queue;
	
	for (int i = 0; i < 7; i++)
		queue.Push(rand() % 5 + 1);
	queue.Print();
	cout << endl;

	for (int i = 0; i < 3; i++)
		queue.Pop();
	queue.Print();
	cout << endl;

	for (int i = 0; i < 5; i++)
		queue.Push(rand() % 5 + 1);
	queue.Print();
	cout << endl;

	for (int i = 0; i < 4; i++)
		queue.Pop();
	queue.Print();
	cout << endl;

	for (int i = 0; i < 5; i++)
		queue.Push(rand() % 5 + 1);
	queue.Print();
	cout << endl;

	cout << endl << "size = " << queue.GetSize() << endl << "count = " << queue.GetCount() << endl;

	for (int i = 0; i < 2; i++)
		queue.Push(rand() % 5 + 1);
	queue.Print();
	cout << endl;

	cout << endl << "size = " << queue.GetSize() << endl << "count = " << queue.GetCount() << endl;

	CQueue<int> new_queue(queue);
	cout << endl << "New queue: ";
	new_queue.Print();
	cout << endl;
	_getch();
}