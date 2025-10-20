#include"bt.h"
#include<vector>
using namespace std;
void postorder(TreeNode* root, vector<int> a){
    if(root == nullptr){
            return;
        }
        //traverse left subtree
        postorder(root->left, a);
        //traverse right subtree
        postorder(root->right, a);
        //take the root at the end
        a.emplace_back(root->val);
}