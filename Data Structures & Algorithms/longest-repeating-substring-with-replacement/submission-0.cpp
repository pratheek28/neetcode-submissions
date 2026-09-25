class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> hashMap;
        int l = 0, maxF = 0;

        int res = 0;

        for (int r = 0; r < s.size(); r++) {
            hashMap[s[r]]++;
            maxF = max(maxF, hashMap[s[r]]);

            while ((r - l + 1) - maxF > k) {
                hashMap[s[l]]--;
                l++;
            }

            res = max(res, (r - l + 1));
        }

        return res;
    }
};
