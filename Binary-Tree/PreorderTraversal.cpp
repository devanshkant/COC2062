#include "bt.h"
#include <vector>
using namespace std;
//Root -> Left Subtree -> Right subtree

void preorder(TreeNode* root, vector<int> &result){
    if(root->left == nullptr){
        return;
    }

    result.emplace_back(root->val);
    preorder(root->left, result);
    preorder(root->right, result);
}
