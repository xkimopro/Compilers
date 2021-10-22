.PHONY: clean distclean default

LLVMCONFIG=llvm-config

CXX=c++
CXXFLAGS=-Wall -std=c++11 `llvm-config --cxxflags`
LDFLAGS=`llvm-config --ldflags --system-libs --libs all`


default: parser

lexer.cpp: lexer.l
	flex -s -o lexer.cpp lexer.l

lexer.o: lexer.cpp lexer.hpp parser.hpp ast.hpp symbol.hpp

parser.hpp parser.cpp: parser.y
	bison  -dv $(F) -o parser.cpp parser.y

parser.o: parser.cpp lexer.hpp ast.hpp symbol.hpp

ast.o: ast.cpp ast.hpp sem.cpp utils.hpp compile.cpp print.cpp 

parser: lexer.o parser.o ast.o
	$(CXX) $(CXXFLAGS) -o parser $^ $(LDFLAGS)

clean:
	$(RM) lexer.cpp parser.cpp parser.hpp parser.output *.o

distclean: clean
	$(RM) parser