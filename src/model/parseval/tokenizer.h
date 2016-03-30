#ifndef TOKENIZER_H
#define TOKENIZER_H


#include <QException>
#include <QString>

#include "symbol.h"


class LexicalException: public QException
{
	public:
        LexicalException(const QString& what);
		~LexicalException();

        const char* what() const throw();

	private:
        const QString _what;
};


class Token
{
	public:
        Token(const QString&, const QString&);
		~Token();

        const QString& getType() const;
        const QString& getValue() const;

	private:
        QString _type;
        QString _value;
};


class Tokenizer
{
	public:
		Tokenizer(SymbolTable*);
		~Tokenizer();

        void setInput(const QString&);
        const Token peek() const;
		void next();	
		bool hasNext() const;	

	private:
		Token _current;
        QString _input;
        const SymbolTable* _table;
};


#endif // TOKENIZER_H
