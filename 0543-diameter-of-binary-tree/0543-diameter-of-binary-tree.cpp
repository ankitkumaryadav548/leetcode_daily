class Solution {
public:

    int level(TreeNode* root) {
        if(root == NULL)
            return 0;

        int ans = 1 + max(level(root->left), level(root->right));

        return ans;
    }

    int diameterOfBinaryTree(TreeNode* root) {

        if(root == NULL)
            return 0;

        int a = level(root->left) + level(root->right);

        int b = diameterOfBinaryTree(root->left);

        int c = diameterOfBinaryTree(root->right);

        return max(a, max(b, c));
    }
};