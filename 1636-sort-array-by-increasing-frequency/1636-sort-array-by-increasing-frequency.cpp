class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (int ele : nums) {
            mp[ele]++;
        }

        typedef pair<int, int> P;
        priority_queue<P, vector<P>, greater<P>> pq;

        for (auto x : mp) {
            pq.push({x.second, -x.first});
        }

        vector<int> ans;

        while (!pq.empty()) {
            int freq = pq.top().first;
            int val = -pq.top().second;
            pq.pop();

            for (int i = 0; i < freq; i++) {
                ans.push_back(val);
            }
        }

        return ans;
    }
};