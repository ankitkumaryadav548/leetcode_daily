class Solution {
public:
    // vector<int> ans;
  // vector<int> preorderTraversal(TreeNode* root) {
    //     if(root == NULL)
    //         return ans;
   
    //     ans.push_back(root->val);

    //     preorderTraversal(root->left);
    //     preorderTraversal(root->right);

    //     return ans;
    // }

    // iterative way to traverse preorder
     vector<int> preorderTraversal(TreeNode* root) {

        vector<int>ans;
        stack<TreeNode*>st;
        if(root != NULL) st.push(root);
        while(st.size()>0){
           
            TreeNode* temp = st.top();
            st.pop();
            ans.push_back(temp->val);
        
        if(temp->right !=NULL) st.push(temp->right);
        if(temp->left !=NULL) st.push(temp->left);
        }   

        return ans;
     }
};