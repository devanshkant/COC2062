#include "bt.h"
using namespace std;
bool search(TreeNode* root, int k){
    if(root == nullptr)
        return false;
    //agar root par hi element mil jaaye
    if(k == root->val)
        return true;
    TreeNode *temp;
    //if the root's value is smaller than the target then, we check in the right subtree
    if(root->val < k)
        temp = root->right;
    //else in the left subtree
    else
        temp = root->left;
    while(temp){
        if(temp->val == k)
            return true;
        if(temp->val < k)
            temp = temp->right;
        else
            temp = temp->left;
    }
    return false;
}
bool RecursiveSearch(TreeNode* root, int k){
    if(root == nullptr)
        return false;
    
    if(root->val == k)
        return true;
    
    if(k > root->val)
        return RecursiveSearch(root->right, k);
    else
        return RecursiveSearch(root->left, k);
}
int main() {
    
    
    return 0;
}