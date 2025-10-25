#ifndef bt_h
#define bt_h
#include<iostream>

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