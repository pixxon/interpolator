#ifndef SYMBOL_H
#define SYMBOL_H


#include <vector>
#include <regex>
#include <functional>


enum Arity { constant, unary, binary };


enum Associativity { left, right, none };


class SymbolInfo
{
public:
	SymbolInfo();
	SymbolInfo(std::string, std::regex, Arity, Associativity, int, std::function<double(double, double)>);

	std::string _name;
	std::regex _rgx;
	Arity _argc;
	Associativity _asso;
	int _prec;
	std::function<double(double, double)> _func;
};


class SymbolTable
{
public:
	SymbolTable();
	~SymbolTable();

	void insertSymbol(std::string, std::regex, Arity, Associativity, int, std::function<double(double, double)>);
	SymbolInfo operator[](std::string);

	class const_iterator
	{
	private:
		std::vector<SymbolInfo>::const_iterator _it;

	public:
		const_iterator(std::vector<SymbolInfo>::const_iterator it);
		~const_iterator();

		const SymbolInfo operator*() const;
		const SymbolInfo* operator->() const;
		bool operator==(const const_iterator& other) const;
		bool operator!=(const const_iterator& other) const;
		const_iterator operator++();
	};

	const_iterator begin();
	const_iterator end();

private:	
	std::vector<SymbolInfo> table;
};


#endif // SYMBOL_H
