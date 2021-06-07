# SudokuSolver
Program to solve Sudoku in very short time.\
Represent a blank as '0'.\
You can also get the number of feasible solutions.\
You can compile by following. (you need C++11(GCC))
```
% sh compile.sh
```

## Parameters
By changing the values of some variables in Parameters.cpp, you can change the conditions of problems.

Size:\
This variable represents the size of problems.\
When Size = 3 (N = Size × Size = 9), the size of problems is 9 × 9.

max_answers:\
This variable represents the maximum number of solutions to be calculated.\
When the number of solutions becomes greater than this value, the calculation is terminated.

## Example
```
% ./SudokuSolver
1 2 3 4 5 6 7 9 8
4 0 0 0 0 0 0 0 2
7 0 9 1 2 3 4 0 5
5 0 7 0 0 0 2 0 3
2 0 4 0 0 0 8 0 9
8 0 1 0 0 0 5 0 6
9 0 2 3 4 5 6 0 7
6 0 0 0 0 0 0 0 4
3 4 5 6 7 8 9 2 1

Found 7 answers.
Showing one of them.

1 2 3  4 5 6  7 9 8
4 5 6  7 8 9  1 3 2
7 8 9  1 2 3  4 6 5

5 6 7  8 9 1  2 4 3
2 3 4  5 6 7  8 1 9
8 9 1  2 3 4  5 7 6

9 1 2  3 4 5  6 8 7
6 7 8  9 1 2  3 5 4
3 4 5  6 7 8  9 2 1

```
```
% ./SudokuSolver
14   362597  8
900  00 0004

50 847 9 203
60 40 00  107


20 5030 806
701 00  0509

809  3124  05
40 00 00 0 02

352  94 67 81

Found an unique answer.

1 4 3  6 2 5  9 7 8
9 2 7  1 8 3  6 5 4
5 6 8  4 7 9  2 1 3

6 3 4  5 9 8  1 2 7
2 9 5  7 3 1  8 4 6
7 8 1  2 6 4  5 3 9

8 7 9  3 1 2  4 6 5
4 1 6  8 5 7  3 9 2
3 5 2  9 4 6  7 8 1

```
```
% ./SudokuSolver
0 0 0  0 0 0  0 0 0
0 0 0  0 0 0  0 0 0
0 0 0  0 0 0  0 0 0

0 0 0  0 0 0  0 0 0
0 0 0  0 0 0  0 0 0
0 0 0  0 0 0  0 0 0

0 0 0  0 0 0  0 0 0
0 0 0  0 0 0  0 0 0
0 0 0  0 0 0  0 0 0

Found more than 100000 answers.
Showing one of them.

1 2 3  4 5 6  7 8 9
7 8 9  1 2 3  4 5 6
4 5 6  7 8 9  1 2 3

3 1 2  8 4 5  9 6 7
6 9 7  3 1 2  8 4 5
8 4 5  6 9 7  3 1 2

2 3 1  5 7 4  6 9 8
9 6 8  2 3 1  5 7 4
5 7 4  9 6 8  2 3 1

```
```
% ./SudokuSolver
496 000 030
048 006 040
050 024 690

031 672 483
800 500 306
609 000 050

962 410 873
080 000 024
000 028 165

Repeating Numbers in ...
  Row    No. 2 4
  Column No. 5 9
  Block  No. 1 6

```
```
% ./SudokuSolver
000000000
000000000
000000000
000000000
000000000
000000000
000000000
000000000
0000000a000

Too many numbers in a line.
Inputs should not include any characters excluding numbers.
```
