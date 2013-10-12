CFLAGS = -g -Wall

tester_functional:	tester_functional.o
	g++ $(CFLAGS) tester_functional.o -o tester_functional

tester_functional.o:		tester_functional.cpp
	g++ $(CFLAGS) -c tester_functional.cpp

clean:
	del *.o *.exe
    
