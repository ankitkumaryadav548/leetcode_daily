
class Solution {
public:
    int sum;
    void reverseInorder(TreeNode* root){
        if(root == NULL) return ;
        reverseInorder(root->right);
        root->val += sum;
        sum = root->val;
        reverseInorder(root->left);

    }
    TreeNode* bstToGst(TreeNode* root) {
        reverseInorder(root);
        return root;
    }
};