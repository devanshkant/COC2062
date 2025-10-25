#include "bt.h"
using namespace std;
TreeNode* RecursiveInsert(TreeNode* root, int k){
    if(root == nullptr)
        return new TreeNode(k);
    
    //a BST can only contain distinct elements
    if(root->val == k){
        return  root;
    }
    if(root->val > k){
        root->left = RecursiveInsert(root->left, k);
    }
    else{
        root->right = RecursiveInsert(root->right, k);
    }
    return root;
}
//iterative method to insert k in a balanced BST
TreeNode* insert(TreeNode* root, int k){

    if(root == nullptr)
        return new TreeNode(k);
    
    TreeNode* temp = root;
    TreeNode* parent = nullptr;
    
    // Find the correct position
    while(temp != nullptr){
        parent = temp;  // Keep track of parent
        
        if(k == temp->val)
            return root;  // Already exists
        
        if(k < temp->val)
            temp = temp->left;
        else
            temp = temp->right;
    }
    
    // Now parent points to where we need to attach new node
    TreeNode* newNode = new TreeNode(k);
    
    if(k < parent->val)
        parent->left = newNode;
    else
        parent->right = newNode;
    
    return root;
}
