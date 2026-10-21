class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& ans) {
        int n = ans.size();
        int count = 0;
        for(int i=0;i<n-1;i++){
            string rev = ans[i];
            reverse(rev.begin() , rev.end());
            for(int j = i+1;j<n;j++){
                if(rev == ans[j]) count++ ;
            }
        }
        return count;
    }
};