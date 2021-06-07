#include <algorithm>
#include <climits>
#include <vector>

#include "Parameters.hpp"
#include "DancingNode.hpp"
#include "MainSolver.hpp"
#include "GridMaker.hpp"


std::vector<int> siz(COLS);
DancingNode* header = new DancingNode();
std::vector<DancingNode*> column(COLS);
std::vector<DancingNode*> temp, ans;


void cover(int c){
    column[c]->unlinkLR();

    for (DancingNode* i = column[c]->D; i != column[c]; i = i->D) {
        for (DancingNode* j = i->R; j != i; j = j->R) {
            j->unlinkUD();
            siz[j->C]--;
        }
    }

    return;
}


void uncover(int c){
    for (DancingNode* i = column[c]->U; i != column[c]; i = i->U) {
        for (DancingNode* j = i->L; j != i; j = j->L) {
            siz[j->C]++;
            j->relinkUD();
        }
    }

    column[c]->relinkLR();

    return;
}


void makeDLXBoard(void){
    header->set(-1);
    DancingNode* current = header;

    for (int i = 0; i < COLS; i++) {
        column[i] = new DancingNode();
        column[i]->set(i);
        current = current->hookRight(column[i]);
    }

    for (int i = 0; i < ROWS; i++) {
        DancingNode* prev = nullptr;
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j]) {
                DancingNode* col = column[j];
                DancingNode* newNode = new DancingNode();
                newNode->set(j);
                if (prev == nullptr) prev = newNode;
                column[j]->U->hookDown(newNode);
                prev = prev->hookRight(newNode);
                siz[j]++;
            }
        }
    }

    return;
}


int selectColumnNodeHeuristic(void){
    int min = INT_MAX;
    int ret = -1;

    for (DancingNode* c = header->R; c != header; c = c->R) {
        if (siz[c->C] < min) {
            min = siz[c->C];
            ret = c->C;
        }
    }

    return ret;
}


void knuthsAlgorithmX(void){
    if (number_of_ans > max_answers) return;
    if (header->R == header){
        if (number_of_ans == 0){
            ans.resize(temp.size());
            std::copy(temp.begin(), temp.end(), ans.begin());
        }
        number_of_ans++;
    }else{
        int c = selectColumnNodeHeuristic();
        cover(c);

        for (DancingNode* r = column[c]->D; r != column[c]; r = r->D) {
            temp.push_back(r);

            for (DancingNode* j = r->R; j != r; j = j->R) cover(j->C);

            knuthsAlgorithmX();
            if (number_of_ans > max_answers) return;

            r = temp.back();
            temp.pop_back();
            c = r->C;

            for (DancingNode* j = r->L; j != r; j = j->L) uncover(j->C);
        }

        uncover(c);
    }

    return;
}


void parseBoard(void){
    for (DancingNode* n : ans) {
        DancingNode* rcNode = n;
        int min = rcNode->C;

        for (DancingNode* tmp = n->L; tmp != n; tmp = tmp->L) {
            int val = tmp->C;
            if (val < min) {
                min = val;
                rcNode = tmp;
            }
        }

        int ans1 = rcNode->C;
        int ans2 = rcNode->R->C;
        int r = ans1 / N;
        int c = ans1 % N;
        int num = (ans2 % N) + 1;
        answer[r][c] = num;
    }
    return ;
}


bool runSolver(void){
    makeExactCoverGrid();
    makeDLXBoard();
    knuthsAlgorithmX();
    if (number_of_ans > 0) parseBoard();
    return number_of_ans > 0;
}