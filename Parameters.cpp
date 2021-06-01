#include <vector>

#include "Parameters.hpp"


const int Size = 3;
const int least_numbers = 0;
const int max_answers = 100000;

int number_of_ans = 0;
const int N = Size * Size;
const int COLS = 4 * N * N;
const int ROWS = N * N * N;

std::vector<std::vector<int>> cell(N, std::vector<int>(N));
std::vector<std::vector<int>> answer(N, std::vector<int>(N));
std::vector<std::vector<bool>> grid(ROWS, std::vector<bool>(COLS));