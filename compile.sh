g++ -c main.cpp -o main.o
g++ -c Checker.cpp -o Checker.o
g++ -c DancingNode.cpp -o DancingNode.o
g++ -c GridMaker.cpp -o GridMaker.o
g++ -c MainSolver.cpp -o MainSolver.o
g++ -c Parameters.cpp -o Parameters.o
g++ main.o Checker.o MainSolver.o GridMaker.o DancingNode.o Parameters.o -o SudokuSolver