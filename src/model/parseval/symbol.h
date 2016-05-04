#ifndef SYMBOL_H
#define SYMBOL_H


#include <QVector>
#include <QRegExp>
#include <QString>
#include <QException>

class SymbolException: public QException
{
    public:
        SymbolException(const QString& what);
        ~SymbolException() throw();

        void raise() const;
        const char* what() const throw();

    private:
        const QString _what;
};

/**
 * @brief BinaryFunction is a typedef for a function which takes two doubles as parameter and returns double.
 */
typedef double(*BinaryFunction)(double, double);

/**
 * @brief The Arity enum is used to express the number of parameters taken by the function.
 */
enum Arity { ARITY_CONSTANT, ARITY_UNARY, ARITY_BINARY };

/**
 * @brief The Associativity enum is needed determine the associativity of binary functions.
 */
enum Associativity { ASSOCIATIVITY_LEFT, ASSOCIATIVITY_RIGHT, ASSOCIATIVITY_NONE };

/**
 * @brief The SymbolInfo class contains every information about symbols.
 */
class SymbolInfo
{
    public:
        /**
         * @brief SymbolInfo empty constructor, so it can be stored in containers.
         */
        SymbolInfo();

        /**
         * @brief SymbolInfo Complete constructor, creates every member with the given value.
         *
         * @param name The name of the symbol.
         * @param rgx Regex matching the symbol.
         * @param arity Arity of the symbol.
         * @param asso Associativity of the symbol.
         * @param prec Precedence of the symbol.
         * @param func Pointer to the symbols function.
         */
        SymbolInfo(const QString& name, const QRegExp& rgx, const Arity& arity, const Associativity& asso, const int& prec, const BinaryFunction& func);

        /**
         * @brief ~SymbolInfo Desctructor
         */
        ~SymbolInfo();


        /**
         * @brief operator== Compares two symbolinfo by their name.
         * @param other The other symbolinfo.
         * @return True if their name equals, false otherwise.
         */
        bool operator==(const SymbolInfo& other) const;

        /**
         * @brief getName Const getter for name.
         * @return Const reference to the name.
         */
        const QString& getName() const;

        /**
         * @brief getRegex Const getter for regex.
         * @return Const reference to the regex.
         */
        const QRegExp& getRegex() const;

        /**
         * @brief getArity Const getter for arity.
         * @return Const reference to arity.
         */
        const Arity& getArity() const;

        /**
         * @brief getAssociativity Const getter for associativity.
         * @return Const reference to associativity.
         */
        const Associativity& getAssociativity() const;

        /**
         * @brief getPrecedence Const getter for precedence.
         * @return Const reference to precedence.
         */
        const int& getPrecedence() const;

        /**
         * @brief getFunction Const getter to the function pointer.
         * @return Const reference to the functions pointer.
         */
        const BinaryFunction& getFunction() const;

    private:
        /**
         * @brief _name Name of the symbol.
         */
        QString _name;

        /**
         * @brief _rgx Regex, matching the function.
         */
        QRegExp _rgx;

        /**
         * @brief _argc Number of arguments of the symbol.
         */
        Arity _argc;

        /**
         * @brief _asso Associativity of the symbol.
         */
        Associativity _asso;

        /**
         * @brief _prec Precedence of the symbol. Bigger number means higher precedence.
         */
        int _prec;

        /**
         * @brief _func Function pointer to the BinaryFunction.
         */
        BinaryFunction _func;
};

/**
 * @brief The SymbolTable class is a Singleton, which means there is exactly one object from it, instead of creating a new one, only a reference is returned.
 */
class SymbolTable
{
    public:
        /**
         * @brief getInstance Static method to get a pointer to the only created object.
         * @return Pointer to the tables only instance.
         */
        static SymbolTable* getInstance();

        /**
         * @brief SymbolTable Removed copy constructor.
         */
        SymbolTable(const SymbolTable&) = delete;

        /**
         * @brief operator = Removed assign operator.
         */
        SymbolTable& operator=(const SymbolTable&) = delete;


        /**
         * @brief insertSymbol Inserts a new symbol, if the name is not taken.
         *
         * @param name The name of the symbol.
         * @param rgx Regex matching the symbol.
         * @param arity Arity of the symbol.
         * @param asso Associativity of the symbol.
         * @param prec Precedence of the symbol.
         * @param func Pointer to the symbols function.
         */
        void insertSymbol(const QString& name, const QRegExp& rgx, const Arity& arity, const Associativity& asso, const int& prec, const BinaryFunction& func);

        /**
         * @brief removeSymbol Removed the symbol from the table.
         *
         * @param name Name of the symbol.
         */
        void removeSymbol(const QString& name);

        /**
         * @brief operator[] Const getter for the symbol.
         * @param name Name of the symbol.
         * @return Const reference to the symbols information.
         */
        const SymbolInfo& operator[](const QString& name) const;


        /**
         * @brief The const_iterator class is used to iterate through symbols.
         */
        class const_iterator
        {
            public:
                /**
                 * @brief const_iterator Constructor for const_iterator.
                 * @param it Iterator to a SymbolInfo.
                 */
                const_iterator(QVector<SymbolInfo>::const_iterator it);

                /**
                 * @brief ~const_iterator Desctructor for iterator.
                 */
                ~const_iterator();


                /**
                 * @brief operator* Dereferences the iterator.
                 * @return Symbol information.
                 */
                const SymbolInfo operator*() const;

                /**
                 * @brief operator-> Returns a pointer for the symbol information.
                 * @return A pointer to the symbol information.
                 */
                const SymbolInfo* operator->() const;

                /**
                 * @brief operator == Compares two const_iterator.
                 * @param other Other instance of const_iterator.
                 * @return True if iterators are pointing ot the same symbol, otherwise false.
                 */
                bool operator==(const const_iterator& other) const;

                /**
                 * @brief operator == Compares two const_iterator.
                 * @param other Other instance of const_iterator.
                 * @return False if iterators are pointing ot the same symbol, otherwise true.
                 */
                bool operator!=(const const_iterator& other) const;

                /**
                 * @brief operator++ Advances the iterator to the next one.
                 * @return The advanced interator.
                 */
                const_iterator operator++();

            private:
                /**
                 * @brief _it Iterator pointing to the symbol.
                 */
                QVector<SymbolInfo>::const_iterator _it;
        };


        /**
         * @brief begin Returns the iterator pointing to the first symbol.
         * @return A const_iterator.
         */
        const_iterator begin() const;

        /**
         * @brief end Returns the iterator pointing behind the last symbol.
         * @return A const_iterator.
         */
        const_iterator end() const;

    private:
        /**
         * @brief SymbolTable Private constructor for SymbolTable.
         */
        SymbolTable();

        /**
         * @brief SymbolTable Private destructor for SymbolTable.
         */
        ~SymbolTable();

        /**
         * @brief _table Container of symbol informations.
         */
        QVector<SymbolInfo> _table;

        /**
         * @brief _instance The only instance of the class.
         */
        static SymbolTable* _instance;
};


#endif // SYMBOL_H
