class Solution {
    void mergeSort(vector<int>& nums, int lo, int hi) {
        if (lo >= hi) return;
        int mid = lo + (hi - lo) / 2;
        mergeSort(nums, lo, mid);
        mergeSort(nums, mid + 1, hi);
        merge(nums, lo, mid, hi);
    }
    void merge(vector<int>& nums, int start, int mid, int end) {
        int start2 = mid + 1;

        if (nums[mid] <= nums[start2]) return;


        while (start <= mid && start2 <= end) {
            if (nums[start] <= nums[start2]) {
                start++;
            }else {
                int val = nums[start2];
                int idx = start2;

                while (idx != start) {
                    nums[idx] = nums[idx - 1];
                    idx--;
                }

                nums[idx] = val;
                start++;
                mid++;
                start2++;
            }
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};