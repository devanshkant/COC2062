#include <vector>
#include "Binary-Tree/bt.h"
using namespace std;

TreeNode* solve(vector<int> &a, int left, int right){
    if(left > right)
        return nullptr;
    int mid = left + (right - left)/2;
//craete new TreeNode
    TreeNode* root = new TreeNode(a[mid]);
//apply the same to left and right subtrees recursively
    root->left = solve(a, left, mid - 1);
    root->right = solve(a, mid + 1, right);
    return root;
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* result = solve(nums, 0, nums.size() - 1);
        return result;
}

int main() {

    
    return 0;
}