class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        int minLen = INT_MAX;
        int minStart = INT_MAX;

        int counter = t.size();

        for (const auto& c : t) {
            mp[c]++;
        }

        int lo = 0, hi = 0;

        while (hi < s.size()) {
            if (mp[s[hi]] > 0) counter--;

            mp[s[hi]]--;
            hi++;

            while (counter == 0) {
                if (hi - lo < minLen) {
                    minStart = lo;
                    minLen = hi - lo;
                }
                mp[s[lo]]++;

                if (mp[s[lo]] > 0) counter++;
                lo++;
            }
        }

        if (minLen == INT_MAX) return "";

        return s.substr(minStart, minLen);
    }
};
