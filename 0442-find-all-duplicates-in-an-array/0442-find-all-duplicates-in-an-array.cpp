class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while (i < n) {
            int correctIdx = nums[i] - 1;
            if (nums[i] == nums[correctIdx]) i++;
            else
                swap(nums[i], nums[correctIdx]);
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) result.push_back(nums[i]);
        }
        return result;
    }
};