#include <cstdio>
#include <vector>

#include "Checker.hpp"
#include "Parameters.hpp"


bool Check(void){
    bool solvable = true;
    int row_counter[N][N + 1] = {}, column_counter[N][N + 1] = {}, block_counter[N][N + 1] = {}, count_numbers = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int val = cell[i][j];
            int blo = Size * (i / Size) + j / Size;
            
            row_counter[i][val]++;
            column_counter[j][val]++;
            block_counter[blo][val]++;
            if(0 < val) count_numbers++;
        }
    }

    std::vector<int> Row, Column, Block;

    for (int sec = 0; sec < N; sec++) {
        bool r = true, c = true, b = true;

        for (int val = 1; val <= N; val++) {
            r &= row_counter[sec][val] < 2;
            c &= column_counter[sec][val] < 2;
            b &= block_counter[sec][val] < 2;
        }

        if (!r) Row.emplace_back(sec);
        if (!c) Column.emplace_back(sec);
        if (!b) Block.emplace_back(sec);
    }
    if (!Row.empty() || !Column.empty() || !Block.empty()) {
        solvable = false;
        printf("Repeating Numbers in ...\n");
        if (!Row.empty()) {
            printf("  Row    No.");
            for (int r : Row) printf(" %d", r + 1);
            printf("\n");
        }

        if (!Column.empty()) {
            printf("  Column No.");
            for (int c : Column) printf(" %d", c + 1);
            printf("\n");
        }

        if (!Block.empty()) {
            printf("  Block  No.");
            for (int b : Block) printf(" %d", b + 1);
            printf("\n");
        }
        printf("\n");
    }

    if (count_numbers < least_numbers) {
        solvable = false;
        printf("Too few numbers. (You need at least %d numbers.)\n", least_numbers);
    }

    return solvable;
}