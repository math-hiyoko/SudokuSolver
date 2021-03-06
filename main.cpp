#include <cassert>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <string>

#include "Checker.hpp"
#include "DancingNode.hpp"
#include "GridMaker.hpp"
#include "MainSolver.hpp"
#include "Parameters.hpp"


int main(void){
    if (Size <= 3) {
        for (int i = 0; i < N;) {
            int j = 0;
            std::string str;
            std::getline(std::cin, str);
            bool number_only = true;
            for (char chr : str) {
                if ((isspace(chr) > 0) || (iscntrl(chr) > 0)) continue;
                if (isdigit(chr) > 0) {
                    if (j < N) cell[i][j] = (int) chr - (int) '0';
                    j++;
                } else {
                    number_only = false;
                }
            }
            if ((j != 0 && j != N) || !number_only) {
                printf("\n");
                if (j < N) printf("Too few numbers in a line.\n");
                if (j > N) printf("Too many numbers in a line.\n");
                if (!number_only) printf("Inputs should not include any characters excluding numbers.\n");
                return 0;
            }
            if (j == N) i++;
        }
    }else{
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                scanf("%d", &cell[i][j]);
    }
    printf("\n");
    if (Check()) {
        if (runSolver()) {
            if (number_of_ans == 1) {
                printf("Found an unique answer.\n");
            }else{
                if(number_of_ans <= max_answers){
                    printf("Found %d answers.\n", number_of_ans);
                }else{
                    printf("Found more than %d answers.\n", max_answers);
                }
                printf("Showing one of them.\n");
            }
            printf("\n");
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    printf("%d ", answer[i][j]);
                    if (j % Size == Size - 1) printf(" ");
                }
                printf("\n");
                if (i % Size == Size - 1) printf("\n");
            }
        }else{
            printf("No answers.\n");
        }
    }
    return 0;
}
