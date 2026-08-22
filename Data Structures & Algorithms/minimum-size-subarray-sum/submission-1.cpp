class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX;

        int lo = 0, hi = 0, curr = 0;

        while (hi < nums.size()) {
            curr += nums[hi];
            hi++;

            while (curr >= target) {
                res = min(res, hi - lo);
                curr -= nums[lo];
                lo++;
            }
        }

        if (res == INT_MAX) return 0;
        return res;
    }
};