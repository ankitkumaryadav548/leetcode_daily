class Solution {
public:

    int partition(vector<int>& nums, int left, int right) {

        int pivot = nums[right];

        int i = left;

        for (int j = left; j < right; j++) {

            if (nums[j] < pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }

        swap(nums[i], nums[right]);

        return i;
    }

    int quickSelect(vector<int>& nums, int left, int right, int target) {

        int pivotIndex = partition(nums, left, right);

        if (pivotIndex == target) {
            return nums[pivotIndex];
        }

        if (target < pivotIndex) {
            return quickSelect(nums, left, pivotIndex - 1, target);
        }

        return quickSelect(nums, pivotIndex + 1, right, target);
    }

    int findKthLargest(vector<int>& nums, int k) {

        int target = nums.size() - k;

        return quickSelect(nums, 0, nums.size() - 1, target);
    }
};
