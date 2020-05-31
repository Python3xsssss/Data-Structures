#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

#include "table.h"
#include "List.h"

using std::endl;
using std::swap;

#define S1MPLE 101

template <typename ValType>
class HashTable : public BasicTable<ValType>
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

	vector<List<Line>> lines;
	size_t hash_arg1 = rand() % S1MPLE, hash_arg2 = rand() % S1MPLE;

	void Resize(){}

	size_t HashFunction(const string& id)
	{
		size_t sumid = 0;
		for (size_t i = 0; i < id.length(); i++)
			sumid += id[i];
		return (((hash_arg1 * sumid + hash_arg2) % S1MPLE) % maxsize);
	}

public:
	HashTable(size_t sz = 10) : BasicTable(sz)
	{
		lines.resize(sz);
	}

	HashTable(const HashTable& table) : BasicTable(table)
	{
		lines = table.lines;
	}

	~HashTable(){}

	ValType Find(const string& id);
	void Insert(const string& id, const ValType& data);
	void Delete(const string& id);
};


template<typename ValType>
typename HashTable<ValType>::Line& HashTable<ValType>::Line::operator=(const Line& ln)
{
	if (this == &ln)
		return *this;

	data = ln.data;
	id = ln.id;
}

template<typename ValType>
inline ValType HashTable<ValType>::Find(const string& id)
{
	size_t index = HashFunction(id);
	List<Line>::Iterator it;
	for (it = lines[index].begin(); it != lines[index].end(); it++)
		if ((*it).id == id)
			break;

	if (it == lines[index].end())
		throw "Error: line with the specified id doesn't exist";

	return (*it).data;
}

template<typename ValType>
inline void HashTable<ValType>::Insert(const string& id, const ValType& data)
{
	size_t index = HashFunction(id);
	List<Line>::Iterator it;
	for (it = lines[index].begin(); it != lines[index].end(); it++)
		if ((*it).id == id)
			break;

	if (it != lines[index].end())
		throw "Error: line with the specified id already exists";

	Line tmp(data, id);
	lines[index].Push_bot(tmp);
	size++;
}

template<typename ValType>
inline void HashTable<ValType>::Delete(const string& id)
{
	size_t index = HashFunction(id);
	List<Line>::Iterator it;
	size_t i = 0;
	for (it = lines[index].begin(); it != lines[index].end(); it++)
	{
		if ((*it).id == id)
			break;
		i++;
	}

	if (it == lines[index].end())
		throw "Error: line with the specified id doesn't exist";

	lines[index].Delete_by_index(i);
	size--;
}

#endif // !_HASHTABLE_H_
