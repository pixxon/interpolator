#include "parser.h"

namespace Model
{
    namespace Parseval
    {
        ParserException::ParserException(const QString& what):
            _what(what)
        {
        }

        ParserException::~ParserException() throw()
        {
        }

        void ParserException::raise() const
        {
            throw *this;
        }

        const char* ParserException::what() const throw()
        {
            return ("Parser hiba: " + _what.toStdString()).c_str();
        }


        Node::Node(Node* left, Node* right, const Token& token):
            _left(left),
            _right(right),
            _token(token)
        {
        }

        Node::~Node()
        {
            if (_left != 0)
            {
                delete _left;
            }
            if (_right != 0)
            {
                delete _right;
            }
        }

        Node* Node::getLeft() const
        {
            return _left;
        }

        Node* Node::getRight() const
        {
            return _right;
        }

        const Token& Node::getToken() const
        {
            return _token;
        }

        Parser::Parser():
            _table(SymbolTable::getInstance()),
            _tokenizer()
        {
        }

        Parser::~Parser()
        {
        }

        void Parser::setInput(const QString& str)
        {
            _tokenizer.setInput(str);
        }

        Node* Parser::parse(const int& min_prec)
        {
            Node* lhs = parse_primary();
            Node* rhs = 0;

            Token peek = _tokenizer.peek();
            if (peek.getValue() != "" && (*_table)[peek.getType()].getArity() != ARITY_BINARY && peek.getType() != "close")
            {
                throw ParserException("Nem várt szimbólum! (" + peek.getValue() + ").");
            }

            while(peek.getValue() != "" && (*_table)[peek.getType()].getArity() == ARITY_BINARY && (*_table)[peek.getType()].getPrecedence() >= min_prec)
            {
                if (!_tokenizer.hasNext())
                {
                    throw ParserException("A bemenet hirtelen véget ért.");
                }

                _tokenizer.next();
                if ((*_table)[peek.getType()].getAssociativity() == ASSOCIATIVITY_LEFT)
                {
                    rhs = parse((*_table)[peek.getType()].getPrecedence() + 1);
                }
                if ((*_table)[peek.getType()].getAssociativity() == ASSOCIATIVITY_RIGHT)
                {
                    rhs = parse((*_table)[peek.getType()].getPrecedence());
                }
                if ((*_table)[peek.getType()].getAssociativity() == ASSOCIATIVITY_NONE)
                {
                    throw ParserException("Nincs definiálva a bináris művelet asszociativitása.");
                }

                lhs = new Node(lhs, rhs, peek);
                peek = _tokenizer.peek();
            }

            return lhs;
        }

        Node* Parser::parse_primary()
        {
            Token peek = _tokenizer.peek();
            if (peek.getType() == "num" || peek.getType() == "var")
            {
                _tokenizer.next();
                return new Node(0, 0, peek);
            }

            if (peek.getType() == "min")
            {
                if (!_tokenizer.hasNext())
                {
                    throw ParserException("A bemenet hirtelen véget ért.");
                }

                _tokenizer.next();
                return new Node(0, parse_primary(), peek);
            }

            if (peek.getType() == "open")
            {
                if (!_tokenizer.hasNext())
                {
                    throw ParserException("A bemenet hirtelen véget ért.");
                }

                _tokenizer.next();
                Node* res = parse(0);

                if (_tokenizer.peek().getType() != "close")
                {
                    throw ParserException("Hiányzó zárójel!");
                }

                _tokenizer.next();
                return res;
            }

            if ((*_table)[peek.getType()].getArity() == ARITY_UNARY)
            {
                if (!_tokenizer.hasNext())
                {
                    throw ParserException("A bemenet hirtelen véget ért.");
                }

                _tokenizer.next();
                return new Node(parse_primary(), 0, peek);
            }

            throw ParserException("Nem várt szimbólum: (" + peek.getValue() + ").");
        }

        Node* Parser::getTree()
        {
            _tokenizer.next();
            Node* root = parse(0);

            if (_tokenizer.peek().getValue() != "")
            {
                throw ParserException("Nem várt szimbólum: (" + _tokenizer.peek().getValue() + ").");
            }

            return root;
        }
    }
}
