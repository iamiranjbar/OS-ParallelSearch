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

worker: workerMain.o worker.o tools.o

		g++ workerMain.o worker.o tools.o -o worker

workerMain.o: workerMain.cpp

		g++ -c workerMain.cpp

worker.o: worker.cpp

		g++ -c worker.cpp

clean: 

		rm *.o
