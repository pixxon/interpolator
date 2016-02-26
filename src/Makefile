default: main.cpp parseval opengl
	g++ -std=c++11 -o run main.cpp parser.o tokenizer.o symbol.o evaluator.o

clean:
	rm -r *.o run


parseval: symbol.o tokenizer.o parser.o evaluator.o

opengl: camera.o shaderprogram.o drawable.o


symbol.o: parseval/symbol.h parseval/symbol.cpp
	g++ -c -std=c++11 "parseval/symbol.cpp"

tokenizer.o: parseval/tokenizer.h parseval/tokenizer.cpp
	g++ -c -std=c++11 "parseval/tokenizer.cpp"

parser.o: parseval/parser.h parseval/parser.cpp
	g++ -c -std=c++11 "parseval/parser.cpp"

evaluator.o: parseval/evaluator.h parseval/evaluator.cpp
	g++ -c -std=c++11 "parseval/evaluator.cpp"


camera.o: opengl/camera.h opengl/camera.cpp
	g++ -c -std=c++11 "opengl/camera.cpp"

shaderprogram.o: opengl/shaderprogram.h opengl/shaderprogram.cpp
	g++ -c -std=c++11 "opengl/shaderprogram.cpp"

drawable.o: opengl/drawable.h opengl/drawable.cpp
	g++ -c -std=c++11 "opengl/drawable.cpp"
