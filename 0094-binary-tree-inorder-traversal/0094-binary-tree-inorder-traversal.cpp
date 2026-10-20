
// class Solution {
// public:
//         // vector<int>ans;
//         vector<int> inorderTraversal(TreeNode* root) {
            // M1 => recursive way to traverse
//         // if(root == NULL) return ans; // we have to return ans vector
//         // inorderTraversal(root->left);
//         // ans.push_back(root->val);
//         // inorderTraversal(root->right);
//         // return ans;

//         //M2 => iterative way to traverse 
//         vector<int>ans;
//         stack<TreeNode*>st;
//         TreeNode* node = root;
//         while(st.size()>0 || node!= NULL){
//             if(node!=NULL){
//                 st.push(node);
//                 node = node->left;
//             }
//             else{
//                 TreeNode* temp = st.top();
//                 st.pop();
//                 ans.push_back(temp->val);
//                 node = temp->right;
//             }
//         }
//         return ans;
//     }
// };



class Solution {
public:
    //M3 => Morris traversal
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        vector<int>ans;
        while(curr != NULL){
            if(curr-> left != NULL){// find predecessor
            TreeNode* pred = curr->left;
            while(pred->right != NULL  && pred->right != curr ){
                pred = pred->right;
            }
            if(pred->right == NULL){
                pred->right = curr;    // LINK
                curr = curr->left;
            }
            else{  // pred->right != NULL
                pred->right = NULL;
                ans.push_back(curr->val); // visit
                curr = curr->right;   
            }
           
            }
            else{ // curr->left == NULL
                ans.push_back(curr->val); // visit
                curr = curr->right;   
            }
        }
        return ans;;
    }
};