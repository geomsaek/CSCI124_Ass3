main:	main.o functions.o menus.o
		g++ -Wall -o ass3 main main.o functions.o menus.o

main.o:	main.cpp header.h menus.o
		g++ -c main.cpp

ass3:	main.o functions.o menus.o
		g++ -Wall -o ass3 main.o functions.o menus.o

functions.o: functions.cpp header.h
		g++ -c functions.cpp
		
menus.o:	menus.cpp menus.h
		g++ -c menus.cpp

cleanLab:
		rm main.o main

cleanTest:
		rm ass3 functions.o menus.o
