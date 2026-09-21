class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int n1 = nums1.size();
        int n2 = nums2.size();
        for(int i=0;i<n1;i++){
            int greater = -1;
            for(int j=0;j<n2;j++){
            if(nums1[i] == nums2[j]){
                for(int k = j+1;k<n2;k++){
                    if(nums2[k]>nums1[i]){
                        greater = nums2[k];
                        break;
                    }
                }
                break;
            }

            }
            ans.push_back(greater);
        }
        return ans;

    }
};