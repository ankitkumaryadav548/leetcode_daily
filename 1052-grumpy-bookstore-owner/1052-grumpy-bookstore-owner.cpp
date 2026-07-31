class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int k = minutes;
        vector<int>&arr = customers ;
        int n = arr.size();
        int maxLoss = 0;
        int preLoss = 0;
        for(int i=0;i<k;i++){
            if(grumpy[i]==1)  preLoss += arr[i];
        }
        maxLoss = preLoss;
        int idx = 0;
        int i = 1;
        int j = k;
        while(j<n){
            // int currLoss = preLoss + arr[j] - arr[i-1];
            int currLoss = preLoss ;
            if(grumpy[j]==1)  currLoss += arr[j];
            if(grumpy[i-1]==1)  currLoss -= arr[i-1];
            if(maxLoss < currLoss){
                maxLoss = currLoss;
                idx = i;
            }
            preLoss = currLoss ;
            i++ ; 
            j++ ;
        }
        //filling 0s in the grumpy array window
        for(int i=idx;i<idx+k;i++){
            grumpy[i] = 0;
        }
        //sum of satisfaction
        int sum = 0;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0) 
            sum += arr[i] ;
        }
        return sum;

    }
};