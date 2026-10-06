
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int a = maxDepth(root -> left);
        int b = maxDepth(root -> right);
        int c = max(a,b);
        return 1 + c;
    }
};