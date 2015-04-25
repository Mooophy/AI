Main.exe	: Main.o graphics.o puzzle.o algorithm.o
	g++ -std=c++11 -Wl,-s -o Main.exe Main.o graphics.o puzzle.o algorithm.o -l gdi32 -static-libgcc -static-libstdc++
			
Main.o	: Main.cpp graphics.h puzzle.h algorithm.h 
	g++ -std=c++11 -c -fpermissive -fconserve-space -Wno-write-strings Main.cpp
	
puzzle.o		: puzzle.cpp puzzle.h
	g++ -std=c++11 -c -fpermissive -fconserve-space -Wno-write-strings  puzzle.cpp
	
algorithm.o	: algorithm.cpp algorithm.h 
	g++ -std=c++11 -c -fpermissive -fconserve-space -Wno-write-strings algorithm.cpp

graphics.o  : graphics.cpp graphics.h
	g++ -std=c++11 -c -fpermissive -fconserve-space -Wno-write-strings graphics.cpp
	
clean:
	del *.o
	del *.exe
	

