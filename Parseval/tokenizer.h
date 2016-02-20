#include <regex>
#include <map>
#include <vector>

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
		Tokenizer(const std::vector<std::string>&, const std::vector<std::regex>&);
		~Tokenizer();

		void setInput(const std::string&);
		Token peekNextToken();
		void advanceNextToken();	
		bool hasNextToken();	

	private:
		std::map<std::string, std::regex> _table;
		Token _current;

		std::string _input;
};
