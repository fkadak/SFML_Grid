CFLAGS = -Wall

all: run

run: compile1 compile2
	./sfml-app

compile2:
	g++ $(CFLAGS) main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

compile1:
	g++ -c $(CFLAGS) main.cpp

clean:
	rm -rf *o sfml-app
