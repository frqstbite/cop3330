date: driver.o date.o
	g++ driver.o date.o -o date

driver.o: driver.cpp date.h
	g++ -c driver.cpp date.h

date.o: date.cpp date.h
	g++ -c date.cpp date.h
