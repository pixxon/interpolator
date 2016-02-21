#include "symbol.h"

SymbolInfo::SymbolInfo()
{
}

SymbolInfo::SymbolInfo(std::regex rgx, Arity argc, Associativity asso, int prec, std::function<double(double, double)> func)
{
	_rgx = rgx;
	_argc = argc;
	_asso = asso;
	_prec = prec;
	_func = func;
}


std::map<std::string, SymbolInfo> SymbolTable::table = std::map<std::string, SymbolInfo>();

void SymbolTable::insertSymbol(std::string name, std::regex rgx, Arity argc, Associativity asso, int prec, std::function<double(double, double)> func)
{
	table[name] = SymbolInfo(rgx, argc, asso, prec, func);
}