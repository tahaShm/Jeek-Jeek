a.out: main.o  functions.o exceptions.o reply.o comment.o jeek.o user.o jeekjeek.o
	g++ main.o functions.o exceptions.o reply.o comment.o jeek.o user.o jeekjeek.o -o a.out
main.o: main.cpp
	g++ -c main.cpp
functions.o: functions.cpp
	g++ -c functions.cpp
exceptions.o: exceptions.cpp
	g++ -c exceptions.cpp
reply.o: reply.cpp
	g++ -c reply.cpp
comment.o: comment.cpp
	g++ -c comment.cpp
jeek.o: jeek.cpp
	g++ -c jeek.cpp
user.o: user.cpp
	g++ -c user.cpp
jeekjeek.o: jeekjeek.cpp
	g++ -c jeekjeek.cpp
clean:
	rm -rf *.o	