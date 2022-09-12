
Dame : main.o board.o
	g++ -o Dame main.o board.o

main.o : main.cpp
	g++ -c main.cpp

board.o : board.cpp
	g++ -c board.cpp

. PHONY : install
install : executable
	sudo cp ./Dame/bin
	sudo chmod 555 /bin/Dame
	sudo chown root:root /bin/Dame

. PHONY : clean
clean :
	rm *.o
	rm Dame
