#include "bt.h"
using namespace std;
int depth(TreeNode* root, TreeNode* target, int curr = 0){
    if(root == nullptr)
        return -1;
    if(root == target)
        return curr;
    int leftDepth = depth(root->left, target, curr + 1);
    if(leftDepth != -1) 
        return leftDepth;
    return depth(root->right, target, curr + 1);
}