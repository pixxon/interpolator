run: main.cpp parseval
	g++ -std=c++11 -o run main.cpp tokenizer.o

parseval:
	g++ -c -std=c++11 "Parseval/tokenizer.cpp"

clean:
	rm -r *.o
