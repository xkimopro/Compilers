LLVMCONFIG=llvm-config-10
CXXFLAGS=-Wall -std=c++11 `$(LLVMCONFIG) --cxxflags`
LDFLAGS=`$(LLVMCONFIG) --ldflags --system-libs --libs all`

llama: lexer.o parser.o sem.o compile.o print.o
	$(CXX) $(CXXFLAGS) -o llama $^ $(LDFLAGS)

parser.hpp parser.cpp: parser.y
	bison  -dv $(F) -o parser.cpp parser.y

lexer.cpp: lexer.l parser.hpp
	flex -s -o lexer.cpp lexer.l

sem.o: ast.hpp
compile.o: ast.hpp
print.o: ast.hpp

clean:
	$(RM) lexer.cpp parser.cpp parser.hpp parser.output *.o

distclean: clean
	$(RM) llama