class Solution {
public:
    int level(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(level(root->left),level(root->right));
    }
    void preOrder(TreeNode* root , vector<int>&ans, int level){
        if(root == NULL) return ;
        ans[level] = root -> val;
        preOrder(root->left,ans,level+1);
        preOrder(root->right,ans,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans(level(root),0);
        preOrder(root,ans,0);
        return ans;
    }
};