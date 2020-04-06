#ifndef _CYCLIC_QUEUE_H_
#define _CYCLIC_QUEUE_H_

#include <iostream>
#include <vector>

using std::size_t;
using std::vector;
using std::cout;
using std::endl;

#define MAX_CQUEUE_SIZE 1000

template <typename ValType>
class CQueue
{
private:
	vector<ValType> buf;
	size_t count, size;
	int top_ind, bot_ind;
	
	void Resize()
	{
		if (size == MAX_CQUEUE_SIZE)
			throw "Error: stack overflow";
		size_t new_size = size + size / 2 + 1;
		if (new_size > MAX_CQUEUE_SIZE)
			new_size = MAX_CQUEUE_SIZE;
		vector<ValType> new_buf(new_size);
		for (size_t i = bot_ind; i < size; i++)
			new_buf[i - bot_ind] = buf[i];
		for (size_t i = 0; i < bot_ind; i++)
			new_buf[size - bot_ind + i] = buf[i];
		bot_ind = 0;
		top_ind = size - 1;
		buf = new_buf;
		size = new_size;
	}

public:
	CQueue(size_t s = 10)
	{
		if (size < 0)
			throw "Error: illegal size";
		size = s;
		count = 0;
		buf.resize(size);
		top_ind = -1;
		bot_ind = 0;
	}

	CQueue(const CQueue& cque)
	{
		buf = cque.buf;
		size = cque.size;
		count = cque.count;
		top_ind = cque.top_ind;
		bot_ind = cque.bot_ind;
	}

	~CQueue() {}

	bool Full() { return (count == size); }
	bool Empty() { return (count == 0); }
	size_t GetSize() { return size; }
	size_t GetCount() { return count; }

	void Push(ValType elem)
	{
		if (Full())
			Resize();
		else if (top_ind < size - 1)
			top_ind++;
		else
			top_ind = 0;
		buf[top_ind] = elem;
		count++;
	}

	ValType Pop()
	{
		if (Empty())
			throw "Error: stack underflow";
		ValType tmp = buf[bot_ind];
		buf[bot_ind] = 0;
		count--;
		if (bot_ind < size - 1)
			bot_ind++;
		else
			bot_ind = 0;
		return tmp;
	}

	ValType Top()
	{
		if (Empty())
			throw "Error: stack underflow";
		return buf[top_ind];
	}

	void Print()
	{
		size_t high = (bot_ind < top_ind) ? top_ind : size - 1;
		for (size_t i = bot_ind; i <= high; i++)
			cout << buf[i] << ' ';
		if (top_ind <= bot_ind)
			for (size_t i = 0; i <= top_ind; i++)
				cout << buf[i] << ' ';
	}
};

#endif // !_STACK_H_
