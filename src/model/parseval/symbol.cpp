#include "symbol.h"


SymbolInfo::SymbolInfo()
{
}

SymbolInfo::SymbolInfo(const QString& name, const QRegExp& rgx, const Arity& argc, const Associativity& asso, const int& prec, const binary_function& func):
    _name(name),
    _rgx(rgx),
    _argc(argc),
    _asso(asso),
    _prec(prec),
    _func(func)
{
}

SymbolInfo::~SymbolInfo()
{
}

const QString& SymbolInfo::getName() const
{
    return _name;
}

const QRegExp& SymbolInfo::getRegex() const
{
    return _rgx;
}

const Arity& SymbolInfo::getArity() const
{
    return _argc;
}

const Associativity& SymbolInfo::getAssociativity() const
{
    return _asso;
}

const int& SymbolInfo::getPrecedence() const
{
    return _prec;
}

const binary_function& SymbolInfo::getFunction() const
{
    return _func;
}


SymbolTable::SymbolTable()
{
}

SymbolTable::~SymbolTable()
{
}

SymbolTable* SymbolTable::_instance = 0;

SymbolTable* SymbolTable::getInstance()
{
    if (_instance == 0)
    {
        _instance = new SymbolTable();
    }
    return _instance;
}

void SymbolTable::insertSymbol(const QString& name, const QRegExp& rgx, const Arity& argc, const Associativity& asso, const int& prec, const binary_function& func)
{
    _table.push_back(SymbolInfo(name, rgx, argc, asso, prec, func));
}

const SymbolInfo& SymbolTable::operator[](const QString& name) const
{
    QVector<SymbolInfo>::const_iterator it = _table.begin();
    while (it != _table.end())
	{
        if (it->getName() == name)
		{
			return *it;
		}
		++it;
    }
}


SymbolTable::const_iterator SymbolTable::begin() const
{
    return const_iterator(_table.begin());
}

SymbolTable::const_iterator SymbolTable::end() const
{
    return const_iterator(_table.end());
}


SymbolTable::const_iterator::const_iterator(QVector<SymbolInfo>::const_iterator it):
    _it(it)
{
}

SymbolTable::const_iterator::~const_iterator()
{
}

const SymbolInfo SymbolTable::const_iterator::operator*() const
{
	return *_it;
}

const SymbolInfo* SymbolTable::const_iterator::operator->() const
{
	return &(*_it);
}

bool SymbolTable::const_iterator::operator==(const SymbolTable::const_iterator& other) const
{
	return other._it == _it;
}

bool SymbolTable::const_iterator::operator!=(const SymbolTable::const_iterator& other) const
{
	return other._it != _it;
}

SymbolTable::const_iterator SymbolTable::const_iterator::operator++()
{
    return _it++;
}
