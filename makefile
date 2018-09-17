output: main.o Block.o BlockChain.o Transaction.o
	g++ main.o Block.o BlockChain.o Transaction.o -o main && make clean

main.o: main.cpp
	g++ -c  main.cpp

Block.o: src/Block.cpp include/Block.h
	g++ -c  src/Block.cpp

BlockChain.o: src/BlockChain.cpp include/BlockChain.h
	g++ -c  src/BlockChain.cpp

Transaction.o: src/Transaction.cpp include/Transaction.h
	g++ -c  src/Transaction.cpp

clean:
	rm *.o