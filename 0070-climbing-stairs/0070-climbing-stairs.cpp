class Solution {
public:
    //memoization 
    int st(int n , vector<int>&ans){
        if(n == 0 || n == 1) return 1;
        if(ans[n] != -1) return ans[n];
        return ans[n]  = st(n-1  , ans)+st(n-2 , ans);
    }
    int climbStairs(int n) {
        vector<int>ans(n+1 , -1) ;
        return st(n , ans);

    }
};