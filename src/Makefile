run: main.cpp symbol.o tokenizer.o parser.o evaluator.o
	g++ -std=c++11 -o run main.cpp parser.o tokenizer.o symbol.o evaluator.o

symbol.o: parseval/symbol.h parseval/symbol.cpp
	g++ -c -std=c++11 "parseval/symbol.cpp"

tokenizer.o: parseval/tokenizer.h parseval/tokenizer.cpp
	g++ -c -std=c++11 "parseval/tokenizer.cpp"

parser.o: parseval/parser.h parseval/parser.cpp
	g++ -c -std=c++11 "parseval/parser.cpp"

evaluator.o: parseval/evaluator.h parseval/evaluator.cpp
	g++ -c -std=c++11 "parseval/evaluator.cpp"

clean:
	rm -r *.o run
