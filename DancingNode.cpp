#include "DancingNode.hpp"


DancingNode::DancingNode(void){
    L = R = U = D = this;
    C = -1;
}


DancingNode* DancingNode::hookDown(DancingNode* n){
    n->D = this->D;
    n->D->U = n;
    n->U = this;
    this->D = n;
    return n;
}


DancingNode* DancingNode::hookRight(DancingNode* n){
    n->R = this->R;
    n->R->L = n;
    n->L = this;
    this->R = n;
    return n;
}


void DancingNode::unlinkLR(void){
    this->L->R = this->R;
    this->R->L = this->L;
    return;
}


void DancingNode::relinkLR(void){
    this->L->R = this->R->L = this;
    return;
}


void DancingNode::unlinkUD(void){
    this->U->D = this->D;
    this->D->U = this->U;
    return;
}


void DancingNode::relinkUD(void){
    this->U->D = this->D->U = this;
    return;
}


void DancingNode::set(int c){
    this->L = this->R = this->U = this->D = this;
    C = c;
    return;
}