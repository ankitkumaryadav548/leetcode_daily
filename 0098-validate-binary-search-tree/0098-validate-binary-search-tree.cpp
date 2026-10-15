
class Solution {
public:
    void InOrder(TreeNode* root, vector<int>& ans) {
        if(root == NULL) return;

        InOrder(root->left, ans);
        ans.push_back(root->val);
        InOrder(root->right, ans);
    }

    bool isValidBST(TreeNode* root) {
        vector<int> ans;
        InOrder(root, ans);

        for(int i = 0; i < ans.size() - 1; i++) {
            if(ans[i] >= ans[i+1])
                return false;
        }

        return true;
    }
};
