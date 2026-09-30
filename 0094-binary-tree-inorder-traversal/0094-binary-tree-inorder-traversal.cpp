
class Solution {
public:
        vector<int>ans;
        vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL) return ans; // we have to return ans vector
        inorderTraversal(root->left);
        ans.push_back(root->val);
        inorderTraversal(root->right);
        return ans;
    }
};