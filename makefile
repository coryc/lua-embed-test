all: main.cpp
	g++ -g -Wall -o calc main.cpp -I/usr/include/lua5.2/ -llua5.2

clean:
	$(RM) calc