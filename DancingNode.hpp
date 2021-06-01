#ifndef DANCINGNODE_HPP
#define DANCINGNODE_HPP

class DancingNode{
    public:
        int C;
        DancingNode *L, *R, *U, *D;

        DancingNode(void);
        DancingNode* hookDown(DancingNode*);
        DancingNode* hookRight(DancingNode*);
        void unlinkLR(void);
        void relinkLR(void);
        void unlinkUD(void);
        void relinkUD(void);
        void set(int);
};

#endif