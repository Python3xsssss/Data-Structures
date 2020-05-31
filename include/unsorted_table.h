#ifndef _UNSTABLE_H_
#define _UNSTABLE_H_

#include "table.h"

using std::endl;
using std::swap;

template <typename ValType>
class UnsortedTable : public BasicTable<ValType>
{
protected:

	struct Line 
	{
		ValType data;
		string id;

		Line() {}
		Line(ValType your_data, string your_id) : data(your_data), id(your_id) {}
		Line(const Line& ln) : data(ln.data), id(ln.id) {}

		~Line() {}

		Line& operator=(const Line& ln);

		bool operator==(const Line& ln) const { return (id == ln.id); }
		bool operator!=(const Line& ln) const { return (id != ln.id); }
	};

	vector<Line> lines;

	void Resize()
	{
		if (size == MAX_TABLE_SIZE)
			throw "Error: table overflow";
		maxsize = size + size / 2 + 1;
		if (maxsize > MAX_TABLE_SIZE)
			maxsize = MAX_TABLE_SIZE;
		vector<Line> new_lines(maxsize);
		for (size_t i = 0; i < size; i++)
			new_lines[i] = lines[i];
		lines.swap(new_lines);
	}

public:
	UnsortedTable(size_t sz = 10) : BasicTable(sz) 
	{
		lines.resize(sz);
	}

	UnsortedTable(const UnsortedTable& table) : BasicTable(table)
	{
		lines = table.lines;
	}

	~UnsortedTable(){}

	ValType Find(const string& id);
	void Insert(const string& id, const ValType& data);
	void Delete(const string& id);

	template<typename ValType>
	friend ostream& operator<<(ostream& out, UnsortedTable<ValType>& table)
	{
		for (size_t i = 0; i < table.size; i++)
			out << table.lines[i].id << "   " << table.lines[i].data << endl;
		return out;
	}
};


template<typename ValType>
typename UnsortedTable<ValType>::Line& UnsortedTable<ValType>::Line::operator=(const Line& ln)
{
	if (this == &ln)
		return *this;

	data = ln.data;
	id = ln.id;
}

template<typename ValType>
inline ValType UnsortedTable<ValType>::Find(const string& id)
{
	size_t i;
	for (i = 0; i < size; i++)
		if (lines[i].id == id)
			break;

	if (i == size)
		throw "Error: line with the specified id doesn't exist";
	
	return lines[i].data;
}

template<typename ValType>
inline void UnsortedTable<ValType>::Insert(const string& id, const ValType& data)
{
	size_t i;
	for (i = 0; i < size; i++)
		if (lines[i].id == id)
			break;

	if (i < size)
		throw "Error: line with the specified id already exists";

	if (size == maxsize)
		Resize();

	Line tmp(data, id);
	lines[i] = tmp;
	size++;
}

template<typename ValType>
inline void UnsortedTable<ValType>::Delete(const string& id)
{
	size_t i;
	for (i = 0; i < size; i++)
		if (lines[i].id == id)
			break;

	if (i == size)
		throw "Error: line with the specified id doesn't exist";

	lines[i] = lines[size - 1];
	size--;
}

#endif // !_UNSTABLE_H_
