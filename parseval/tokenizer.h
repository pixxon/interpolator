#ifndef TOKENIZER_H
#define TOKENIZER_H


#include <exception>
#include <string>


class LexicalException: public std::exception
{
	public:
		LexicalException(const std::string& what);
		~LexicalException();

		virtual const char* what() const throw();

	private:
		std::string _what;
};


class Token
{
	public:
		Token();
		Token(const std::string&, const std::string&);
		~Token();

		std::string getType() const;
		std::string getValue() const;

	private:
		std::string _type;
		std::string _value;
};


class Tokenizer
{
	public:
		Tokenizer();
		~Tokenizer();

		void setInput(const std::string&);
		Token peekNextToken();
		void advanceNextToken();	
		bool hasNextToken();	

	private:
		Token _current;
		std::string _input;
};


#endif // TOKENIZER_H
