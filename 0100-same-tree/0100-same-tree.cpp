class Solution {
public:

    int check(TreeNode* p, TreeNode* q) {

        if(p == NULL && q == NULL)
            return 1;

        if(p == NULL || q == NULL)
            return 0;

        if(p->val != q->val)
            return 0;

        int a = check(p->left, q->left);
        int c = check(p->right, q->right);

        if(a && c)
            return 1;
        else
            return 0;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return check(p, q);
    }
};