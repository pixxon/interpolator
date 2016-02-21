#include <iostream>
#include <functional>
#include <regex>
#include <math.h>

#include "parseval/parser.h"
#include "parseval/tokenizer.h"
#include "parseval/symbol.h"

#include <set>


std::set<int> s;

void indent(int level)
{
	for (int i = 0; i < level; i++)
	{
		if (s.count(i) > 0)
		{
			std::cout << "| ";
		}
		else
		{
			std::cout << "  ";
		}
	}
}

void tee(int level)
{
	indent(level);
	std::cout << "|-";
	s.insert(level);
}

void ell(int level)
{
	indent(level);
	std::cout << "`-";
	s.erase(level);
}

void print(Node* node, int level)
{
	if(node == nullptr)
	{
		std::cout << "null" << std::endl;
	}
	else
	{
		std::cout << node->_token.getType() << std::endl;
		if (node->_right != nullptr || node->_left != nullptr)
		{
			tee(level);
			print(node->_left, level + 1);
			ell(level);
			print(node->_right, level + 1);
		}
	}
}






int main()
{
	SymbolTable::insertSymbol("var", std::regex("^(x|y)"), constant, none, 0, 0);
	SymbolTable::insertSymbol("num", std::regex("^[[:d:]](\\.[[:d:]])?"), constant, none, 0, 0);
	SymbolTable::insertSymbol("open", std::regex("^\\("), constant, none, 0, 0);
	SymbolTable::insertSymbol("close", std::regex("^\\)"), constant, none, 0, 0);

	SymbolTable::insertSymbol("add", std::regex("^\\+"), binary, left, 1, [](double a, double b){ return a + b; });
	SymbolTable::insertSymbol("min", std::regex("^-"), binary, left, 1, [](double a, double b){ return a - b; });
	SymbolTable::insertSymbol("mul", std::regex("^\\*"), binary, left, 2, [](double a, double b){ return a * b; });
	SymbolTable::insertSymbol("div", std::regex("^/"), binary, left, 2, [](double a, double b){ return a / b; });

	SymbolTable::insertSymbol("sin", std::regex("^sin"), unary, none, 0, [](double a, double b){ return sin(a); });
	SymbolTable::insertSymbol("cos", std::regex("^cos"), unary, none, 0, [](double a, double b){ return cos(a); });
	SymbolTable::insertSymbol("tg", std::regex("^tg"), unary, none, 0, [](double a, double b){ return tan(a); });
	SymbolTable::insertSymbol("ctg", std::regex("^ctg"), unary, none, 0, [](double a, double b){ return 1 / tan(a); });

	Tokenizer tokenizer;

	std::string input;
	std::cin >> input;
	tokenizer.setInput(input);

	Parser parser(tokenizer);
	Node* root = parser.getTree();

	print(root, 0);



	return 0;
}