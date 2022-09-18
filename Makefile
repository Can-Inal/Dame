Dame : main.o board.o piece.o
	g++ -o Dame main.o board.o piece.o

main.o : main.cpp
	g++ -c -std=c++1z main.cpp

board.o : board.cpp
	g++ -c -std=c++1z board.cpp

piece.o : piece.cpp
	g++ -c -std=c++1z piece.cpp

. PHONY : install
install : executable
	sudo cp ./Dame/bin
	sudo chmod 555 /bin/Dame
	sudo chown root:root /bin/Dame

. PHONY : clean
clean :
	rm *.o
	rm Dame
