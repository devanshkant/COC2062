#include "bt.h"
#include <algorithm>
using namespace std;
int Height(TreeNode* root){
    if(root == nullptr)
        return 0;
    return 1 + max(Height(root->left), Height(root->right));
}
bool isBalanced(TreeNode* root){
    if(root == nullptr)
        return true;
    int leftHeight = Height(root->left);
    int rightHeight = Height(root->right);
    return abs(leftHeight - rightHeight) <= 1 && 
            isBalanced(root->left) && 
            isBalanced(root->right);
}