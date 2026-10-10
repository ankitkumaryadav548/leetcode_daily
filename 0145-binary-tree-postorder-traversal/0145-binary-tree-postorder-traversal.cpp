
class Solution {
public:
    // vector<int>ans;
    vector<int> postorderTraversal(TreeNode* root) {
        // if(root == NULL) return ans;
        // postorderTraversal(root->left);
        // postorderTraversal(root->right);
        // ans.push_back(root->val);
        // return ans;

        vector<int>ans;
        stack<TreeNode*>st;
        if(root != NULL) st.push(root);
        while(st.size()>0){
           
            TreeNode* temp = st.top();
            st.pop();
            ans.push_back(temp->val);
        
        if(temp->left !=NULL) st.push(temp->left);
        if(temp->right !=NULL) st.push(temp->right);
        }   
        reverse(ans.begin(),ans.end());
        return ans;
    }
};