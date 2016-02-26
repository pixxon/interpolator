#include "symbol.h"
#include <iostream>

SymbolInfo::SymbolInfo()
{
}

SymbolInfo::SymbolInfo(std::string name, std::regex rgx, Arity argc, Associativity asso, int prec, std::function<double(double, double)> func)
{
	_name = name;
	_rgx = rgx;
	_argc = argc;
	_asso = asso;
	_prec = prec;
	_func = func;
}


SymbolTable::SymbolTable()
{
}

SymbolTable::~SymbolTable()
{
}

void SymbolTable::insertSymbol(std::string name, std::regex rgx, Arity argc, Associativity asso, int prec, std::function<double(double, double)> func)
{
	table.push_back(SymbolInfo(name, rgx, argc, asso, prec, func));
}

SymbolInfo SymbolTable::operator[](std::string name)
{
	std::vector<SymbolInfo>::const_iterator it = table.begin();
	while (it != table.end())
	{
		if (it->_name == name)
		{
			return *it;
		}
		++it;
	}
	throw std::exception();
}


SymbolTable::const_iterator SymbolTable::begin()
{
	return const_iterator(table.begin());
}

SymbolTable::const_iterator SymbolTable::end()
{
	return const_iterator(table.end());
}


SymbolTable::const_iterator::const_iterator(std::vector<SymbolInfo>::const_iterator it)
{
	_it = it;
}

SymbolTable::const_iterator::~const_iterator()
{
}

const SymbolInfo SymbolTable::const_iterator::operator*() const
{
	return *_it;
}

const SymbolInfo* SymbolTable::const_iterator::operator->() const
{
	return &(*_it);
}

bool SymbolTable::const_iterator::operator==(const SymbolTable::const_iterator& other) const
{
	return other._it == _it;
}

bool SymbolTable::const_iterator::operator!=(const SymbolTable::const_iterator& other) const
{
	return other._it != _it;
}

SymbolTable::const_iterator SymbolTable::const_iterator::operator++()
{
	_it++;
}
