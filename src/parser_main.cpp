#include <iostream>
#include <functional>
#include <regex>
#include <math.h>

#include "parseval/parser.h"
#include "parseval/tokenizer.h"
#include "parseval/symbol.h"
#include "parseval/evaluator.h"

#include <ctime>
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

void print(const Node* node, int level)
{
	if(node == nullptr)
	{
		std::cout << "null" << std::endl;
	}
	else
	{
		std::cout << node->getToken().getType() << std::endl;
		if (node->getRight() != nullptr || node->getLeft() != nullptr)
		{
			tee(level);
			print(node->getLeft(), level + 1);
			ell(level);
			print(node->getRight(), level + 1);
		}
	}
}

int main()
{
	SymbolTable table;
	table.insertSymbol("var", std::regex("^(x|y)"), constant, none, 0, 0);
	table.insertSymbol("num", std::regex("^[[:d:]](\\.[[:d:]])?"), constant, none, 0, 0);
	table.insertSymbol("open", std::regex("^\\("), constant, none, 0, 0);
	table.insertSymbol("close", std::regex("^\\)"), constant, none, 0, 0);

	table.insertSymbol("add", std::regex("^\\+"), binary, left, 1, [](double a, double b){ return a + b; });
	table.insertSymbol("min", std::regex("^-"), binary, left, 1, [](double a, double b){ return a - b; });
	table.insertSymbol("mul", std::regex("^\\*"), binary, left, 2, [](double a, double b){ return a * b; });
	table.insertSymbol("div", std::regex("^/"), binary, left, 2, [](double a, double b){ return a / b; });
	table.insertSymbol("pow", std::regex("^\\^"), binary, right, 3, [](double a, double b){ return pow(a, b); });

	table.insertSymbol("sin", std::regex("^sin"), unary, none, 0, [](double a, double b){ return sin(a); });
	table.insertSymbol("cos", std::regex("^cos"), unary, none, 0, [](double a, double b){ return cos(a); });
	table.insertSymbol("tg", std::regex("^tg"), unary, none, 0, [](double a, double b){ return tan(a); });
	table.insertSymbol("ctg", std::regex("^ctg"), unary, none, 0, [](double a, double b){ return 1 / tan(a); });

	std::string input = "((x-1)^2+y^2-4)((x+1)^2+y^2-4)(x^2+(y-3^(1/2))^2-4)";

	Evaluator evaluator(&table);
	evaluator.setExpression(input);

	clock_t start = clock();
	for (double x = 0; x < 1000; x+=1)
	{
		for (double y = 0; y < 100; y+=1)
		{
			evaluator.calculate(x, y);
		}
	}
	clock_t end = clock();
	std::cout << (end - start) / CLOCKS_PER_SEC << std::endl;



	return 0;
}