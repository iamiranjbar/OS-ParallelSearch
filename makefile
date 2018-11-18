all: parSearch
		make clean
	
parSearch: main.o loadBalancer.o tools.o

		g++ main.o loadBalancer.o tools.o -o parSearch

main.o: main.cpp 

		g++ -c main.cpp 

loadBalancer.o: loadBalancer.cpp

		g++ -c loadBalancer.cpp 

tools.o: tools.cpp

		g++ -c tools.cpp

clean: 

		rm *.o
