#pragma once
#ifndef _DHEAP_H_
#define _DHEAP_H_

#include <iostream>
#include <vector>
#include <string>

#define INF 1000000000;

using std::size_t;
using std::ostream;
using std::vector;
using std::string;


template <typename ValType>
class DHeap
{
private:
	struct Node
	{
		ValType data;
		size_t priority;

		Node(ValType your_data, size_t your_priority) : data(your_data), priority(your_priority) {}
		Node(size_t your_priority) : priority(your_priority) {}
		Node(const Node& nd) : data(nd.data), priority(nd.priority) {}

		Node& operator= (const Node& nd) 
		{
			data = nd.data;
			priority = nd.priority;

			return *this;
		}

		bool operator==(const Node& nd) const { return (priority == nd.priority); }
		bool operator!=(const Node& nd) const { return (priority != nd.priority); }
		bool operator>(const Node& nd) const { return (priority > nd.priority); }
		bool operator<(const Node& nd) const { return (priority < nd.priority); }
		bool operator>=(const Node& nd) const { return (priority >= nd.priority); }
		bool operator<=(const Node& nd) const { return (priority <= nd.priority); }
	};

	vector<Node> heap;
	size_t degree;
	size_t size;

	size_t LeftChild(size_t index);
	size_t RightChild(size_t index);
	size_t Parent(size_t index);
	size_t MinChild(size_t index);

	void Diving(size_t index);
	void Emersion(size_t index);
	void GoOnTop(size_t index);

	void Delete(size_t index);//To make it an interface method: search by priority
	void MakeHeap();
	
public:
	DHeap(size_t d = 2) : degree(d), size(0) {}
	DHeap(const vector<size_t>& priorities, size_t vec_size, bool sort, size_t d = 2);
	DHeap(const DHeap& hp) : heap(hp.heap), degree(hp.degree), size(hp.size) {}
	~DHeap() {}

	void Insert(ValType data, size_t priority);
	void DeleteMin();

	void HeapSort();

	template <typename ValType>
	friend ostream& operator<<(ostream& out, DHeap<ValType>& hp)
	{
		size_t counter = 0, amount = 1;
		for (size_t i = 0; i < hp.size; i++)
		{
			out << hp.heap[i].priority;
			counter++;
			if (counter == amount)
			{
				counter = 0;
				amount *= hp.degree;
				out << std::endl;
			}
			else
				out << ' ';
		}

		if (counter != 0)
			out << std::endl;
		return out;
	}
};
#endif // !_DHEAP_H_

template<typename ValType>
inline size_t DHeap<ValType>::LeftChild(size_t index)
{
	if (index >= size)
		throw "Error: the heap doesn't have an element with that index";

	size_t pos = degree * index + 1;
	size_t last = size - 1;

	return pos > last ? 0 : pos;
}

template<typename ValType>
inline size_t DHeap<ValType>::RightChild(size_t index)
{
	if (index >= size)
		throw "Error: the heap doesn't have an element with that index";

	size_t pos = degree * (index + 1);
	size_t last = size - 1;

	return (pos > last) ? last : pos;
}

template<typename ValType>
inline size_t DHeap<ValType>::Parent(size_t index)
{
	if (index >= size) 
		throw "Error: the heap doesn't have an element with that index"; 

	return (index > 0) ? (index - 1) / degree : 0;
}

template<typename ValType>
inline size_t DHeap<ValType>::MinChild(size_t index)
{
	size_t left = LeftChild(index), right = RightChild(index);

	if (left == 0)
		return 0;

	Node min = heap[left];
	size_t tmp = left;
	for (size_t i = left + 1; i <= right; i++)
		if (heap[i] < min)
		{
			min = heap[i];
			tmp = i;
		}
	
	return tmp;

}

template<typename ValType>
inline void DHeap<ValType>::Diving(size_t index)
{
	size_t ind1 = index, ind2 = MinChild(index);

	while (ind2 != 0 && heap[ind1] > heap[ind2])
	{
		Node tmp = heap[ind1];
		heap[ind1] = heap[ind2];
		heap[ind2] = tmp;

		ind1 = ind2;
		ind2 = MinChild(ind2);
	}
}

template<typename ValType>
inline void DHeap<ValType>::Emersion(size_t index)
{
	size_t ind1 = index, ind2 = Parent(index);

	while (ind2 != 0 && heap[ind1] < heap[ind2])
	{
		Node tmp = heap[ind1];
		heap[ind1] = heap[ind2];
		heap[ind2] = tmp;

		ind1 = ind2;
		ind2 = Parent(ind2);
	}

	if (heap[ind1] < heap[ind2])
	{
		Node tmp = heap[ind1];
		heap[ind1] = heap[ind2];
		heap[ind2] = tmp;
	}
}

template<typename ValType>
inline void DHeap<ValType>::Delete(size_t index)
{
	GoOnTop(index);
	DeleteMin();
}

template<typename ValType>
inline void DHeap<ValType>::MakeHeap()
{
	for (size_t i = size - 1; i > 0; i--)
		Diving(i);
	
	Diving(0);
}

template<typename ValType>
inline void DHeap<ValType>::HeapSort()
{
	vector<Node> new_heap;
	size_t new_size = size;
	for (size_t i = 0; i < new_size; i++)
	{
		new_heap.push_back(heap[0]);
		DeleteMin();
	}

	heap = new_heap;
	size = new_size;
}

template<typename ValType>
inline DHeap<ValType>::DHeap(const vector<size_t>& priorities, size_t vec_size, bool sort, size_t d)
{
	degree = d;
	for (size_t i = 0; i < vec_size; i++)
	{
		Node tmp(priorities[i]);
		heap.push_back(tmp);
	}

	size = vec_size;

	MakeHeap();
	if (sort)
		HeapSort();
}

template<typename ValType>
inline void DHeap<ValType>::GoOnTop(size_t index)
{
	heap[index].priority = 0;
	Emersion(index);
}

template<typename ValType>
inline void DHeap<ValType>::Insert(ValType data, size_t priority)
{
	Node new_node(data, priority);
	heap.push_back(new_node);
	size++;
	Emersion(size - 1);
}

template<typename ValType>
inline void DHeap<ValType>::DeleteMin()
{
	heap[0] = heap[size - 1];
	heap.pop_back();

	size--;
	if (size > 1)
		Diving(0);
}

