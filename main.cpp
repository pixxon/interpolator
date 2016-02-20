#include <iostream>

#include "Parseval/tokenizer.h"

int main()
{
	std::vector<std::string> name = {"var", "num", "open", "close", "add", "sin"};
	std::vector<std::regex> regexes = {std::regex("^x"), std::regex("^[[:d:]]"), std::regex("^\\("), std::regex("^\\)"), std::regex("^\\+"), std::regex("^sin")};


	Tokenizer tokenizer(name, regexes);

	tokenizer.setInput("sin(x)+2");

	while(tokenizer.hasNextToken())
	{
		tokenizer.advanceNextToken();
		std::cout << tokenizer.peekNextToken()._type << std::endl;
	}

	return 0;
}