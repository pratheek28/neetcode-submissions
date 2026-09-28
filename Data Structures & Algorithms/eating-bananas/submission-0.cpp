class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = INT_MIN;

        for (const auto& p : piles) {
            right = max(p, right);
        }

        int res = right;

        while (left <= right) {
            int mid = (right + left) / 2;

            long long totalTime = 0;

            for (const auto& p : piles) {
                totalTime += ceil(static_cast<double>(p) / mid);
            }

            if (totalTime <= h) {
                res = mid;
                right = mid - 1;
            }else {
                left = mid + 1;
            }
        }

        return res;
    }
};
