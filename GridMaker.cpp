#include <algorithm>
#include <vector>

#include "DancingNode.hpp"
#include "GridMaker.hpp"
#include "MainSolver.hpp"
#include "Parameters.hpp"


int getIdx(int row, int column, int num){
    return row * N * N + column * N + (num - 1);
}


void sudokuExactCover(void){
    int hBase = 0;

    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++, hBase++)
            for (int n = 1; n <= N; n++)
                grid[getIdx(r, c, n)][hBase] = true;

    for (int r = 0; r < N; r++)
        for (int n = 1; n <= N; n++, hBase++)
            for (int c = 0; c < N; c++)
                grid[getIdx(r, c, n)][hBase] = true;

    for (int c = 0; c < N; c++)
        for (int n = 1; n <= N; n++, hBase++)
            for (int r = 0; r < N; r++)
                grid[getIdx(r, c, n)][hBase] = true;

    for (int br = 0; br < N; br += Size)
        for (int bc = 0; bc < N; bc += Size)
            for (int n = 1; n <= N; n++, hBase++)
                for (int rDelta = 0; rDelta < Size; rDelta++)
                    for (int cDelta = 0; cDelta < Size; cDelta++)
                        grid[getIdx(br + rDelta, bc + cDelta, n)][hBase] = true;

    return;
}


void makeExactCoverGrid(void){
    sudokuExactCover();

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            int val = cell[i][j];
            if (val != 0)
                for (int num = 1; num <= N; num++)
                    if (num != val)
                        fill(grid[getIdx(i, j, num)].begin(), grid[getIdx(i, j, num)].end(), false);
        }

    return;
}