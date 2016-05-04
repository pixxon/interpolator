#ifndef PARSER_H
#define PARSER_H


#include <QException>
#include <QString>


#include "tokenizer.h"
#include "symbol.h"


class ParserException: public QException
{
	public:
        ParserException(const QString& what);
        ~ParserException() throw();

        void raise() const;
        const char* what() const throw();

	private:
        const QString _what;
};


class Node
	{
	private:
        Node* _left;
        Node* _right;
        Token _token;

	public:
        Node(Node* left, Node* right, const Token&);
		~Node();

        Node* getLeft() const;
        Node* getRight() const;
		const Token& getToken() const;
};


class Parser
{
	public:
        Parser();
		~Parser();

		Node* getTree();
        void setInput(const QString& str);

	private:
		SymbolTable* _table;
		Tokenizer _tokenizer;

        Node* parse(const int& min_prec);
        Node* parse_primary();
};


#endif // PARSER_H
