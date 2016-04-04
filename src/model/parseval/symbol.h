#ifndef SYMBOL_H
#define SYMBOL_H


#include <QVector>
#include <QRegExp>
#include <QString>


typedef double(*binary_function)(double, double);


enum Arity { ARITY_CONSTANT, ARITY_UNARY, ARITY_BINARY };


enum Associativity { ASSOCIATIVITY_LEFT, ASSOCIATIVITY_RIGHT, ASSOCIATIVITY_NONE };


class SymbolInfo
{
    public:
        SymbolInfo();
        SymbolInfo(const QString&, const QRegExp&, const Arity&, const Associativity&, const int&, const binary_function&);
        ~SymbolInfo();

        const QString& getName() const;
        const QRegExp& getRegex() const;
        const Arity& getArity() const;
        const Associativity& getAssociativity() const;
        const int& getPrecedence() const;
        const binary_function& getFunction() const;

    private:
        QString _name;
        QRegExp _rgx;
        Arity _argc;
        Associativity _asso;
        int _prec;
        binary_function _func;
};


class SymbolTable
{
    public:
        static SymbolTable* getInstance();

        void insertSymbol(const QString&, const QRegExp&, const Arity&, const Associativity&, const int&, const binary_function&);
        const SymbolInfo& operator[](const QString&) const;

        const_iterator begin() const;
        const_iterator end() const;

        class const_iterator
        {
            private:
                QVector<SymbolInfo>::const_iterator _it;

            public:
                const_iterator(QVector<SymbolInfo>::const_iterator it);
                ~const_iterator();

                const SymbolInfo operator*() const;
                const SymbolInfo* operator->() const;
                bool operator==(const const_iterator& other) const;
                bool operator!=(const const_iterator& other) const;
                const_iterator operator++();
        };

    private:
        SymbolTable();
        ~SymbolTable();

        QVector<SymbolInfo> _table;

        static SymbolTable* _instance;
};


#endif // SYMBOL_H
