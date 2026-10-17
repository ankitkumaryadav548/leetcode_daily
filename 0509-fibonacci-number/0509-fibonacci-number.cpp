class Solution {
public:
    int fib(int n) {
        // M1 => simple recursion 
        // if(n==0) return 0;
        // if(n == 1 ) return 1;
        // return  fib(n-1)+fib(n-2);
        // M2 => using dp  
        vector<int>ans(n+1 , -1);
        ans[0] = 0;
        if(n>=1){
            ans[1] = 1;
        }
        for(int i=2;i<ans.size() ; i++){
            ans[i] = ans[i-1] + ans[i-2];
        }
        return ans[n];

    }
};