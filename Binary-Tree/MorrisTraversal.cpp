//morris traversal for inorder traversal in O(1) space without recursion

#include"bt.h"  //implementation
#include<vector>
using namespace std;

vector<int> inOrder(TreeNode* root) {
    vector<int> res;
    TreeNode* curr = root;

    while (curr != nullptr) {
        if (curr->left == nullptr) {
          
            // If no left child, visit this TreeNode 
            // and go right
            res.push_back(curr->val);
            curr = curr->right;
        }
        else {
          
            // Find the inorder predecessor of curr
            TreeNode* prev = curr->left;
            while (prev->right != nullptr &&
                                 prev->right != curr) {
                prev = prev->right;
            }

            // Make curr the right child of its 
            // inorder predecessor
            if (prev->right == nullptr) {
                prev->right = curr;
                curr = curr->left;
            } 
            else {
              
                // Revert the changes made in 
                // the tree structure
                prev->right = nullptr;
                res.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    return res;
}