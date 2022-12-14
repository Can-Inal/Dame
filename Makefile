UNAME := $(shell uname)


Dame : main.o board.o piece.o player.o game.o
	g++ -o Dame main.o board.o piece.o player.o game.o

main.o : main.cpp
	g++ -c -std=c++1z main.cpp

board.o : board.cpp
	g++ -c -std=c++1z board.cpp

piece.o : piece.cpp
	g++ -c -std=c++1z piece.cpp

player.o : player.cpp	
	g++ -c -std=c++1z player.cpp

game.o : game.cpp
	g++ -c -std=c++1z game.cpp

. PHONY : install
install : executable
	sudo cp ./Dame/bin
	sudo chmod 555 /bin/Dame
	sudo chown root:root /bin/Dame
ifeq ($(UNAME), Linux)
	. PHONY : clean
	clean:
		rm *.o
		rm Dame
endif

ifeq ($(UNAME), Windows_NT)
	. PHONY : clean
	clean :
		del *.o
		del Dame.exe
endif
