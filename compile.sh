g++ -std=c++11 -c main.cpp -o main.o
g++ -std=c++11 -c Checker.cpp -o Checker.o
g++ -std=c++11 -c DancingNode.cpp -o DancingNode.o
g++ -std=c++11 -c GridMaker.cpp -o GridMaker.o
g++ -std=c++11 -c MainSolver.cpp -o MainSolver.o
g++ -std=c++11 -c Parameters.cpp -o Parameters.o
g++ -std=c++11 main.o Checker.o MainSolver.o GridMaker.o DancingNode.o Parameters.o -o SudokuSolver