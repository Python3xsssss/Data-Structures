#ifndef _TABLE_H_
#define _TABLE_H_

#include <iostream>
#include <vector>
#include <string>

#define MAX_TABLE_SIZE 100

using std::size_t;
using std::vector;
using std::string;
using std::ostream;

template <typename ValType>
class BasicTable
{
protected:
	size_t size, maxsize;
	virtual void Resize() = 0;
public:
	BasicTable(size_t sz = 10) : size(0), maxsize(sz) {}
	BasicTable(const BasicTable& table) : size(table.size), maxsize(table.maxsize) {}

	virtual ~BasicTable() {}

	virtual ValType Find(const string& id) = 0;
	virtual void Insert(const string& id, const ValType& data) = 0;
	virtual void Delete(const string& id) = 0;

	template<typename ValType> 
	friend ostream& operator<<(ostream& out, BasicTable<ValType>& table) = 0;
};

#endif // !_TABLE_H_
