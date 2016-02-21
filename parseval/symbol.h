#ifndef SYMBOL_H
#define SYMBOL_H


#include <map>
#include <regex>
#include <functional>


enum Arity { constant, unary, binary };


enum Associativity { left, right, none };


class SymbolInfo
{
public:
	std::regex _rgx;
	Arity _argc;
	Associativity _asso;
	int _prec;
	std::function<double(double, double)> _func;

	SymbolInfo();
	SymbolInfo(std::regex, Arity, Associativity, int, std::function<double(double, double)>);
};


class SymbolTable
{
public:
	static std::map<std::string, SymbolInfo> table;

	static void insertSymbol(std::string, std::regex, Arity, Associativity, int, std::function<double(double, double)>);
private:
};

#endif // SYMBOL_H
