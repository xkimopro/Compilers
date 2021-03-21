.PHONY: default clean distclean
CXX=c++
CXXFLAGS=-Wall -std=c++11
default: lexer.cpp lexer

lexer.cpp: lexer.l
	flex -s -o lexer.cpp lexer.l 

lexer: lexer.cpp 
	c++ lexer.cpp -o lexer


clean:
	$(RM) lexer.cpp lexer
