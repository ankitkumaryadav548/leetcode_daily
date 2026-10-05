class Solution {
public:
    int ans = 0;

    int sum(TreeNode* root) {
        if (root == NULL)
            return 0;

        int leftSum = sum(root->left);
        int rightSum = sum(root->right);

        ans += abs(leftSum - rightSum);

        return leftSum + rightSum + root->val;
    }

    int findTilt(TreeNode* root) {
        sum(root);
        return ans;
    }
};