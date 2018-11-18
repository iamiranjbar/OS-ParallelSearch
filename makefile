all: parSearch 
		make worker
		make clean

parSearch: main.o loadBalancer.o tools.o

		g++ main.o loadBalancer.o tools.o -o parSearch

main.o: main.cpp 

		g++ -c main.cpp 

loadBalancer.o: loadBalancer.cpp

		g++ -c loadBalancer.cpp 

tools.o: tools.cpp

		g++ -c tools.cpp

worker: workerMain.cpp

		g++ workerMain.cpp -o worker

clean: 

		rm *.o
