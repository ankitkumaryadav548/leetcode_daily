// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         vector<int>ans;
//         int n1 = nums1.size();
//         int n2 = nums2.size();
//         for(int i=0;i<n1;i++){
//             int greater = -1;
//             for(int j=0;j<n2;j++){
//             if(nums1[i] == nums2[j]){
//                 for(int k = j+1;k<n2;k++){
//                     if(nums2[k]>nums1[i]){
//                         greater = nums2[k];
//                         break;
//                     }
//                 }
//                 break;
//             }

//             }
//             ans.push_back(greater);
//         }
//         return ans;

//     }
// };

//using in stack => in one pass
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        stack<int> st;
        vector<int> greater(nums2.size());

        // Traverse nums2 from right to left
        for(int i = nums2.size() - 1; i >= 0; i--) {

            // Remove elements which cannot be next greater
            while(!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            // If stack is empty, no greater element exists
            if(st.empty()) {
                greater[i] = -1;
            }
            else {
                greater[i] = st.top();
            }

            // Push current element
            st.push(nums2[i]);
        }

        vector<int> ans;

        // Find nums1 elements in nums2
        for(int i = 0; i < nums1.size(); i++) {

            for(int j = 0; j < nums2.size(); j++) {

                if(nums1[i] == nums2[j]) {
                    ans.push_back(greater[j]);
                    break;
                }
            }
        }

        return ans;
    }
};
