sphere: driver.o sphere.o
	g++ driver.o sphere.o -o sphere

driver.o: driver.cpp sphere.h
	g++ -c driver.cpp sphere.h

sphere.o: sphere.cpp sphere.h
	g++ -c sphere.cpp sphere.h
