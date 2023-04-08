.PHONY: llama clean distclean
CXX=c++
LLVMCONFIG=llvm-config-13
CXXFLAGS=-Wall `$(LLVMCONFIG) --cxxflags` -g
LDFLAGS=`$(LLVMCONFIG) --ldflags --system-libs --libs all`

llama: lexer.o parser.o sem.o compile.o print.o
	$(CXX) $(CXXFLAGS) -o llama $^ $(LDFLAGS)

parser.hpp parser.cpp: parser.y lexer.hpp ast.hpp
	bison -dv -o parser.cpp parser.y

lexer.cpp: lexer.l lexer.hpp parser.hpp ast.hpp
	flex -s -o lexer.cpp lexer.l

sem.o: ast.hpp
compile.o: ast.hpp
print.o: ast.hpp

clean:
	$(RM) lexer.cpp parser.cpp parser.hpp parser.output *.o

distclean: clean
	$(RM) llama