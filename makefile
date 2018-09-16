output: main.o Block.o BlockChain.o
	g++ main.o Block.o BlockChain.o -o main && make clean

main.o: main.cpp
	g++ -c  main.cpp

Block.o: src/Block.cpp include/Block.h
	g++ -c  src/Block.cpp

BlockChain.o: src/BlockChain.cpp include/BlockChain.h
	g++ -c  src/BlockChain.cpp

# Http.o: source/Http.cpp include/Http.h
# 	g++ -c  source/Http.cpp

# Server.o: source/Server.cpp include/Server.h
# 	g++ -c  source/Server.cpp

clean:
	rm *.o