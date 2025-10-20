/*
NOT
IN 
SYLLABUS of COC2062
*/
#include "bt.h"
#include<vector>
using namespace  std;

void levelorder(TreeNode* root, int level, vector<vector<int>> &res){
    if(root == nullptr){
        return;
    }
    if(res.size() <= level){
        res.push_back({});
    }
    res[level].emplace_back(root->val);
    levelorder(root->left, level + 1, res);
    levelorder(root->right, level + 1, res);
}
vector<vector<int>> Traverse(TreeNode* root) {
        vector<vector<int>> ans;
        levelorder(root, 0, ans);   //0 level se start kiya
        return ans;
}
int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(12);
    root->left->left = new TreeNode(7);
    root->left->left->left = new TreeNode(17);
    root->left->left->right = new TreeNode(23);
    root->right = new TreeNode(13);
    root->right->left = new TreeNode(14);
    root->right->left->left = new TreeNode(27);
    root->right->left->right = new TreeNode(3);
    root->right->right = new TreeNode(2);
    root->right->right->left = new TreeNode(8);
    root->right->right->right = new TreeNode(11);
    vector<vector<int>> ans = Traverse(root);
    cout << "\n Level order elements = ";
    for(int i = 0; i < ans.size(); ++i){
        cout << '[';
        for (int j = 0; j < ans[i].size() ; ++j){
            cout << ans[i][j] << ' ';
        }
        cout << ']';
    }
    return 0;
}