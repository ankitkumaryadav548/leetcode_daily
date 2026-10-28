class Solution {
public:
    typedef pair<int , int>pi;
    vector<int> topKFrequent(vector<int>& arr, int k) {
        map<int , int> mp;
        for(int ele : arr){
            mp[ele]++ ; 
        }
        priority_queue<pi , vector<pi> , greater<pi>>pq;
        for(auto x : mp){
            pq.push({x.second , x.first});
            if(pq.size()>k) pq.pop();
        }
        vector<int>ans;
        while(pq.size()>0){
            int ele = pq.top().second;
            ans.push_back(ele);
            pq.pop();
        }
        return ans;
    }

};