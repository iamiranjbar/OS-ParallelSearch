all: parSearch
		make clean
	
parSearch: main.o loadBalancer.o

		g++ main.o loadBalancer.o -o parSearch

main.o: main.cpp 

		g++ -c main.cpp 

loadBalancer.o: loadBalancer.cpp

		g++ -c loadBalancer.cpp 

clean: 

		rm *.o
