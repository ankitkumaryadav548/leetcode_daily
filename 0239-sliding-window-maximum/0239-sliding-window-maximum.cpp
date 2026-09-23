// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {

//         int n = nums.size();

//         vector<int> ans;

//         for(int i = 0; i < n-k+1; i++){

//             int Max = INT_MIN;

//             for(int j = i; j < i+k; j++){

//                 if(nums[j] > Max)
//                     Max = nums[j];
//             }

//             ans.push_back(Max);
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {

        int n = arr.size();

        // Find Next Greater Index
        vector<int> ngi(n);

        stack<int> st;
        st.push(n - 1);

        ngi[n - 1] = n;

        for(int i = n - 2; i >= 0; i--) {

            while(st.size() > 0 && arr[st.top()] <= arr[i]) {
                st.pop();
            }

            if(st.size() == 0)
                ngi[i] = n;
            else
                ngi[i] = st.top();

            st.push(i);
        }

        vector<int> ans;

        int j = 0;

        // Find maximum of every window
        for(int i = 0; i < n-k+1; i++) {

            if(j < i)
                j = i;

            int mx = arr[j];

            while(j < i+k) {

                mx = arr[j];

                // NGE is outside current window
                if(ngi[j] >= i+k)
                    break;

                // Jump to NGE
                j = ngi[j];
            }

            ans.push_back(mx);
        }

        return ans;
    }
};