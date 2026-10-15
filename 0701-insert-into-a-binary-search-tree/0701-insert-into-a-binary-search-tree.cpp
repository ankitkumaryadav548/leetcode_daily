
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* temp = new TreeNode(val);
        if(root == NULL) return temp;
        else if(root->val > val){
            if(root->left == NULL){
                root->left = temp;
            }
            else insertIntoBST(root->left , val);
        }
        else {
            if(root->right == NULL) root->right = temp;
            else insertIntoBST(root->right , val);
        }
        return root;
    }
};