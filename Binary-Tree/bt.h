#ifndef BINARY_TREE_H
#define BINARY_TREE_H

class TreeNode{
public:
    int val;
    TreeNode *left;   
    TreeNode *right;
    
    TreeNode(int v){
        this-> val = v;
        left = nullptr;
        right = nullptr;
    }
};

#endif
