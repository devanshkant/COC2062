#include"bt.h"
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> LOT(TreeNode* root){
    if(!root)
        return {};
    queue<TreeNode*> q;
    q.push(root);
    vector<vector<int>> ans;
    int curr = 0;
    while(!q.empty()){
        int len = q.size();
        ans.push_back({});
        for(int i = 0; i < len; ++i){
            TreeNode* temp = q.front();
            q.pop();
            ans[curr].emplace_back(temp->val);
            
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        ++curr;
    }
    return ans;
}