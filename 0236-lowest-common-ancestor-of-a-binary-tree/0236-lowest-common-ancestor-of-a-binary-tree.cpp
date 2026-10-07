
class Solution {
public:
    bool exits(TreeNode* root, TreeNode* target){
        if(root == NULL) return false;
        if(root == target) return true;
        return exits(root->left , target) || exits(root->right , target);

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q) return root ;
        else if(exits(root -> left , p) && exits(root->right , q)) return root ;
        else if(exits(root -> left , q) && exits(root->right , p)) return root ;
        else if(exits(root ->left ,p) && exits(root->left,q)) return lowestCommonAncestor(root->left , p, q);
        else return lowestCommonAncestor(root->right , p, q);
    }
};