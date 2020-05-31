#include "d_heap.h"
#include <conio.h>
#include <cstdlib>
#include <ctime>
int main()
{
	srand(time(NULL));
	vector<size_t> mas;
	size_t size = 7;
	for (size_t i = 0; i < size; i++)
	{
		mas.push_back(rand() % 100);
		std::cout << mas[i] << ' ';
	}
	std::cout << std::endl;

	DHeap<size_t> heap(mas, size, false, 2);
	std::cout << std::endl << heap;

	heap.Insert(3, 1);
	std::cout << std::endl << heap;

	heap.DeleteMin();
	std::cout << std::endl << heap;

	heap.HeapSort();
	std::cout << std::endl << heap;

	DHeap<size_t> hp(2);

	hp.Insert(3, 1);
	std::cout << std::endl << hp;

	hp.DeleteMin();
	std::cout << std::endl << hp;

	_getch();
}