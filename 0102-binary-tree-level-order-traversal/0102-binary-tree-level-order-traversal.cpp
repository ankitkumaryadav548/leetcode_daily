
class Solution {
public:
    int level(TreeNode* root) {
        if (root == NULL)
            return 0;
        return 1 + max(level(root->left), level(root->right));
    }

    // reverse order level wise(from left to right)
    void nthLevel(TreeNode* root, int current, int targetLevel,vector<int>&v) {
        if (root == NULL)  return;
        if (current == targetLevel) {
            v.push_back(root->val);
            return;
        }

        nthLevel(root->left, current + 1, targetLevel,v);
        nthLevel(root->right, current + 1, targetLevel,v);
    }

    void lOrder(TreeNode* root,vector<vector<int>>&ans) {
        int n = level(root);
        for (int i = 1; i <= n; i++) {
            vector<int>v;
            nthLevel(root, 1, i,v);
            ans.push_back(v);
            cout << endl;
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        lOrder(root,ans);
        return ans;
    }
};