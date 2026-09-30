class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {

        if(root == NULL)
            return false;

        // If it is a leaf node
        if(root->left == NULL && root->right == NULL)
            return root->val == targetSum;

        targetSum = targetSum - root->val;

        bool left = hasPathSum(root->left, targetSum);
        bool right = hasPathSum(root->right, targetSum);

        return left || right;
    }
};