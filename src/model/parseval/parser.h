#ifndef PARSER_H
#define PARSER_H


#include <QException>
#include <QString>


#include "tokenizer.h"
#include "symbol.h"

namespace Model
{
    namespace Parseval
    {
        /**
         * @brief The ParserException class shows errors in parsing.
         */
        class ParserException: public QException
        {
            public:
                /**
                 * @brief ParserException Stores a message.
                 */
                ParserException(const QString&);
                ~ParserException() throw();

                /**
                 * @brief raise Throws this exception.
                 */
                void raise() const;

                /**
                 * @brief what Returns the message.
                 */
                const char* what() const throw();

            private:
                /**
                 * @brief _what The message.
                 */
                const QString _what;
        };

        /**
         * @brief The Node class Builds up a syntax tree.
         */
        class Node
        {
            private:
                /**
                 * @brief _left Pointer to left child.
                 */
                Node* _left;
                /**
                 * @brief _right Pointer to right child.
                 */
                Node* _right;
                /**
                 * @brief _token Stored information.
                 */
                Token _token;

            public:
                /**
                 * @brief Node Sets every member to the given value.
                 */
                Node(Node*, Node*, const Token&);
                ~Node();

                /**
                 * @brief getLeft Returns pointer to the left child.
                 */
                Node* getLeft() const;
                /**
                 * @brief getRight Returns pointer to the right child.
                 */
                Node* getRight() const;
                /**
                 * @brief getToken Retuns the stored token.
                 */
                const Token& getToken() const;
        };

        /**
         * @brief The Parser class Creates a syntax tree from the string.
         */
        class Parser
        {
            public:
                Parser();
                ~Parser();

                Node* getTree();
                void setInput(const QString&);

            private:
                SymbolTable* _table;
                Tokenizer _tokenizer;

                Node* parse(const int&);
                Node* parse_primary();
        };
    }
}


#endif // PARSER_H
