class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lo = 0;
        int hi = 0;
        int res = 0;
        unordered_map<char, int> mp;

        while (hi < s.size()) {
            if (mp.find(s[hi]) != mp.end() && mp[s[hi]] != 0) {
                mp[s[lo]]--;
                res = max(res, hi - lo);
                lo++;
            }else {
                mp[s[hi]]++;
                hi++;
            }
        }

        return max(res, hi - lo);
    }
};
