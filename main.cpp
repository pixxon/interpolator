#include <iostream>
#include <functional>
#include <regex>

#include "parseval/parser.h"
#include "parseval/tokenizer.h"
#include "parseval/symbol.h"


int main()
{
	SymbolTable::insertSymbol("var", std::regex("^(x|y)"), constant, none, 0, 0);
	SymbolTable::insertSymbol("num", std::regex("^[[:d:]](\\.[[:d:]])?"), constant, none, 0, 0);
	SymbolTable::insertSymbol("open", std::regex("^\\("), constant, none, 0, 0);
	SymbolTable::insertSymbol("close", std::regex("^\\)"), constant, none, 0, 0);

	SymbolTable::insertSymbol("add", std::regex("^\\+"), constant, none, 0, 0);
	SymbolTable::insertSymbol("min", std::regex("^-"), constant, none, 0, 0);
	SymbolTable::insertSymbol("mul", std::regex("^\\*"), constant, none, 0, 0);
	SymbolTable::insertSymbol("div", std::regex("^/"), constant, none, 0, 0);

	SymbolTable::insertSymbol("sin", std::regex("^sin"), constant, none, 0, 0);
	SymbolTable::insertSymbol("cos", std::regex("^cos"), constant, none, 0, 0);
	SymbolTable::insertSymbol("tg", std::regex("^tg"), constant, none, 0, 0);
	SymbolTable::insertSymbol("ctg", std::regex("^ctg"), constant, none, 0, 0);

	Tokenizer tokenizer;

	std::string input;
	std::cin >> input;
	tokenizer.setInput(input);

	Parser parser(tokenizer);
	Node* root = parser.getTree();



	return 0;
}