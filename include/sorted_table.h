#ifndef _STABLE_H_
#define _STABLE_H_

#include "table.h"

#define MAX_SUB_LINES_SIZE 5

using std::endl;
using std::swap;
using std::stol;

template <typename ValType>
class SortedTable : public BasicTable<ValType>
{
protected:

	struct Line 
	{
		ValType data;
		string id;
		bool is_deleted;

		Line() {}
		Line(ValType your_data, string your_id) : data(your_data), id(your_id), is_deleted(false) {}
		Line(const Line& ln) : data(ln.data), id(ln.id), is_deleted(ln.is_deleted) {}

		~Line() {}

		Line& operator=(const Line& ln);

		bool operator==(const Line& ln) const { return (id == ln.id); }
		bool operator!=(const Line& ln) const { return (id != ln.id); }
	};

	vector<Line> lines;
	vector<Line> sub_lines;
	size_t sub_size, sub_maxsize, deleted;

	bool BinarySearch(const string id, vector<Line>& target, size_t amount, int& index);
	void Resize() {}
	void Merge();

public:
	SortedTable(size_t sz = 10) : BasicTable(sz)
	{
		lines.resize(sz);
		sub_lines.resize(MAX_SUB_LINES_SIZE);
		sub_size = 0;
		sub_maxsize = MAX_SUB_LINES_SIZE;
		deleted = 0;
	}

	SortedTable(const SortedTable& table) : BasicTable(table)
	{
		lines = table.lines;
		sub_lines = table.sub_lines;
		sub_size = table.sub_size;
		sub_maxsize = table.sub_maxsize;
		deleted = table.deleted;
	}

	~SortedTable(){}

	ValType Find(const string& id);
	void Insert(const string& id, const ValType& data);
	void Delete(const string& id);
	size_t GetSize() { return size + sub_size; }

	template<typename ValType>
	friend ostream& operator<<(ostream& out, SortedTable<ValType>& table)
	{
		table.Merge();
		for (size_t i = 0; i < table.size; i++)
			out << table.lines[i].id << "   " << table.lines[i].data << endl;
		return out;
	}
};


template<typename ValType>
typename SortedTable<ValType>::Line& SortedTable<ValType>::Line::operator=(const Line& ln)
{
	if (this == &ln)
		return *this;

	data = ln.data;
	id = ln.id;
	is_deleted = ln.is_deleted;
}

template<typename ValType>
inline bool SortedTable<ValType>::BinarySearch(const string id, vector<Line>& target, size_t size_of_target, int& index)
{
	int down = 0, up = size_of_target, mid;
	bool is_found = false;
	while (down < up)
	{
		mid = int(up + (down - up) / 2.0);
		if (id < target[mid].id)
			up = mid;
		else if (id > target[mid].id)
			down = mid + 1;
		else
		{
			is_found = (!target[mid].is_deleted);
			up = mid;
			down = mid;
			index = mid;
		}
	}

	if (!is_found)
		index = up;

	return is_found;
}

template<typename ValType>
inline void SortedTable<ValType>::Merge()
{
	int i = 0, j = 0;
	vector<Line> new_lines;

	while (i < size + deleted && j < sub_size)
	{
		if (lines[i].is_deleted)
		{
			i++;
		}
			
		else if (lines[i].id < sub_lines[j].id)
		{
			new_lines.push_back(lines[i]);
			i++;
		}
		else
		{
			new_lines.push_back(sub_lines[j]);
			j++;
		}
	}

	if (i == size + deleted)
		for (; j < sub_size; j++)
			new_lines.push_back(sub_lines[j]);
	else
		for (; i < size + deleted; i++)
			if (!lines[i].is_deleted)
				new_lines.push_back(lines[i]);

	lines.swap(new_lines);
	size += sub_size;
	sub_size = 0;
	deleted = 0;
}

template<typename ValType>
inline ValType SortedTable<ValType>::Find(const string& id)
{
	int index;
	if (!BinarySearch(id, lines, size + deleted, index))
	{
		if (!BinarySearch(id, sub_lines, sub_size, index))
			throw "Error: line with the specified id doesn't exist";
		return sub_lines[index].data;
	}
	
	return lines[index].data;
}

template<typename ValType>
inline void SortedTable<ValType>::Insert(const string& id, const ValType& data)
{
	int index;
	if (sub_size == sub_maxsize)
		Merge();
	
	if (BinarySearch(id, lines, size + deleted, index) || BinarySearch(id, sub_lines, sub_size, index))
		throw "Error: line with the specified id already exists";

	Line tmp(data, id);
	for (size_t i = sub_size; i > index; i--)
		sub_lines[i] = sub_lines[i - 1];

	sub_lines[index] = tmp;

	sub_size++;
}

template<typename ValType>
inline void SortedTable<ValType>::Delete(const string& id)
{
	int index;
	if (!BinarySearch(id, lines, size + deleted, index))
	{
		if (!BinarySearch(id, sub_lines, sub_size, index))
			throw "Error: line with the specified id doesn't exist";
		sub_lines.erase(sub_lines.begin() + index);
		sub_size--;
		return;
	}

	lines[index].is_deleted = true;
	size--;
	deleted++;
}

#endif // !_STABLE_H_
