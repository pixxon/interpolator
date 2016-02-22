run: main.cpp tokenizer.o parser.o symbol.o
	g++ -std=c++11 -o run main.cpp parser.o tokenizer.o symbol.o

parser.o: parseval/parser.h parseval/parser.cpp
	g++ -c -std=c++11 "parseval/parser.cpp"

tokenizer.o: parseval/tokenizer.h parseval/tokenizer.cpp
	g++ -c -std=c++11 "parseval/tokenizer.cpp"

symbol.o: parseval/symbol.h parseval/symbol.cpp
	g++ -c -std=c++11 "parseval/symbol.cpp"

clean:
	rm -r *.o run
