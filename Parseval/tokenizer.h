#include <regex>
#include <map>

class Token
{
	public:
		Token();
		~Token();

		std::string _type;
		std::string _value;

	private:
};

class Tokenizer
{
	public:
		Tokenizer();
		~Tokenizer();

		Token peekNextToken();
		void advanceNextToken();	
		bool hasNextToken();	

	private:
		std::map<std::string, std::regex> _table;
		Token _current;

		std::string _input;
};
