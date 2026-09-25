class Solution {
public:
    int maxArea(vector<int>& heights) {
        int lo = 0;
        int hi = heights.size() - 1;

        int res = INT_MIN;

        while (lo <= hi) {
            int currArea = min(heights[lo], heights[hi]) * (hi - lo);
            res = max(res, currArea);

            if (heights[lo] < heights[hi]) {
                lo++;
            }else {
                hi--;
            }
        }

        return res;
    }
};
