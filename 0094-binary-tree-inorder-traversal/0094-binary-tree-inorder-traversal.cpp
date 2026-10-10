
class Solution {
public:
        // vector<int>ans;
        vector<int> inorderTraversal(TreeNode* root) {
        // if(root == NULL) return ans; // we have to return ans vector
        // inorderTraversal(root->left);
        // ans.push_back(root->val);
        // inorderTraversal(root->right);
        // return ans;

        //iterative way to traverse 
        vector<int>ans;
        stack<TreeNode*>st;
        TreeNode* node = root;
        while(st.size()>0 || node!= NULL){
            if(node!=NULL){
                st.push(node);
                node = node->left;
            }
            else{
                TreeNode* temp = st.top();
                st.pop();
                ans.push_back(temp->val);
                node = temp->right;
            }
        }
        return ans;
    }
};