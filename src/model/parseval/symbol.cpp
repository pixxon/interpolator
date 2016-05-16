#include "symbol.h"

namespace Model
{
    namespace Parseval
    {
        SymbolException::SymbolException(const QString& what):
            _what(what)
        {
        }

        SymbolException::~SymbolException() throw()
        {
        }

        const char* SymbolException::what() const throw()
        {
            return ("Nem található szimbólum: " + _what.toStdString()).c_str();
        }


        void SymbolException::raise() const
        {
            throw *this;
        }

        SymbolInfo::SymbolInfo()
        {
        }

        SymbolInfo::SymbolInfo(const QString& name, const QRegExp& rgx, const Arity& argc, const Associativity& asso, const int& prec, const BinaryFunction& func):
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

        bool SymbolInfo::operator==(const SymbolInfo& other) const
        {
            return (_name == other._name);
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

        const BinaryFunction& SymbolInfo::getFunction() const
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


        void SymbolTable::insertSymbol(const QString& name, const QRegExp& rgx, const Arity& arity, const Associativity& asso, const int& prec, const BinaryFunction& func)
        {
            for (const SymbolInfo& symbol : _table)
            {
                if (symbol.getName() == name)
                {
                    throw SymbolException("Már létező szimbólum: " + name);
                }
            }

            _table.push_back(SymbolInfo(name, rgx, arity, asso, prec, func));
        }

        void SymbolTable::removeSymbol(const QString &name)
        {
            for (const SymbolInfo& symbol : _table)
            {
                if (symbol.getName() == name)
                {
                    _table.removeOne(symbol);
                    return;
                }
            }
            throw SymbolException("Nem létező szimbólum: " + name);
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
            throw SymbolException("Nem létező szimbólum: " + name);
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
    }
}
