.PHONY: clean distclean llama

LLVMCONFIG=llvm-config-10
CXXFLAGS=-Wall -std=c++11 `$(LLVMCONFIG) --cxxflags`
LDFLAGS=`$(LLVMCONFIG) --ldflags --system-libs --libs all`

llama: lexer.o parser.o ast.o
	$(CXX) $(CXXFLAGS) -o llama $^ $(LDFLAGS)

parser.hpp parser.cpp: parser.y
	bison  -dv $(F) -o parser.cpp parser.y

lexer.cpp: lexer.l parser.hpp
	flex -s -o lexer.cpp lexer.l

clean:
	$(RM) lexer.cpp parser.cpp parser.hpp parser.output *.o

distclean: clean
	$(RM) llama