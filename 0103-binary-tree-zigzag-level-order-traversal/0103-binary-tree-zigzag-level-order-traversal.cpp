class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true;

        while(!q.empty()) {
            int n = q.size();
            vector<int> level(n);

            for(int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();

                int index;

                if(leftToRight)
                    index = i;
                else
                    index = n - 1 - i;

                level[index] = temp->val;

                if(temp->left != NULL)
                    q.push(temp->left);

                if(temp->right != NULL)
                    q.push(temp->right);
            }

            ans.push_back(level);
            leftToRight = !leftToRight;
        }

        return ans;
    }
};