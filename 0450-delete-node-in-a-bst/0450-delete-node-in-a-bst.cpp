
class Solution {
public:
    TreeNode* iop(TreeNode* root ){
        if(root == NULL) return NULL;
        TreeNode* pre = root->left;
        while(pre->right != NULL){
            pre = pre->right;
        }
        return pre;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root->val == key){
            //case 1 => if node is leaf node
            if(root->left == NULL && root->right == NULL) return NULL;
            //case 2 => if node have one child 
            else if(root->left == NULL || root->right == NULL){
                if(root->left != NULL) return root->left;
                else return root->right;
            } 
            // case 3 => if node have both child
            else{   // (root->left != NULL && root->right != NULL)
                //replace the root with its inorder predeccessor/successor 
                //after replaceing delete the pre/succ 
                TreeNode* pred = iop(root );
                root->val = pred->val;
                root->left = deleteNode(root->left , pred->val);
            }
        }
        else if(root->val > key){ // go left
            root->left = deleteNode(root->left , key);
        }
        else{ // go right
            root->right = deleteNode(root->right , key);
        }
        return root;
    }
};