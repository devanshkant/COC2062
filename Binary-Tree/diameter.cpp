#include "bt.h"
#include<algorithm>
using namespace std;

pair<int,int> diameterHelper(TreeNode* root){
    if(!root){
        pair<int,int> p = make_pair(0,0);
        return p;
    }
    pair<int,int> left = diameterHelper(root->left);
    pair<int,int> right = diameterHelper(root->right);
    int op1 = left.first, op2 = right.first, op3 = left.second + right.second + 1;
    pair<int,int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;
    return ans;
}
int diameter(TreeNode* root){
    return diameterHelper(root).first;
}
