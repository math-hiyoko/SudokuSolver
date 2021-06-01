#ifndef MAINSOLVER_HPP
#define MAINSOLVER_HPP

void cover(int);
void uncover(int);
void makeDLXBoard(void);
int selectColumnNodeHeuristic(void);
void knuthsAlgorithmX(void);
void parseBoard(void);
bool runSolver(void);

#endif