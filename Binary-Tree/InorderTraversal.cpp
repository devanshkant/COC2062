#include "bt.h"     //contains TreeNode implementation 
#include<vector>
using namespace std;
void inorder(TreeNode* root, vector<int> &ans){
    if(root == NULL){
        return;
    }
    inorder(root->left, ans);
    ans.emplace_back(root->val);
    inorder(root->right, ans);
}

int main(){
    TreeNode *root = new TreeNode(12);
    root->left = new TreeNode(21);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(30);
    root->left->right = new TreeNode(51);
    root->right->right = new TreeNode(93);
    
    vector<int> result;
    inorder(root, result);
    
    for(int i : result){
        cout << i << ' ';
    }
    return 0;
}

