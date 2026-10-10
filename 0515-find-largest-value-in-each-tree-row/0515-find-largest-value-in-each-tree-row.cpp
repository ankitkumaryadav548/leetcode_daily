
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;

        if(root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int n = q.size();
            int maxVal = INT_MIN;

            for(int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();

                maxVal = max(maxVal, temp->val);

                if(temp->left != NULL)
                    q.push(temp->left);

                if(temp->right != NULL)
                    q.push(temp->right);
            }

            ans.push_back(maxVal);
        }

        return ans;
    }
};
