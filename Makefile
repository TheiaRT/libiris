CXX = clang++
CFLAGS = -Ofast -g -std=c++11 -pthread -Wall -Wpedantic -Werror
LFLAGS = -lpthread

all: client server

client: tcp_client.o sampleclient.cpp
	$(CXX) $(CFLAGS) -o client tcp_client.o sampleclient.cpp

server: tcp_server.o sampleserver.cpp
	$(CXX) $(CFLAGS) -o server tcp_server.o sampleserver.cpp

clean:
	rm -f *.o

%.o: %.cpp
	$(CXX) $(CFLAGS) -c -o $@ $<
