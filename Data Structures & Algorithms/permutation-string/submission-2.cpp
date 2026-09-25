class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        unordered_map<char, int> fMap;

        for (const char c : s1) {
            fMap[c]++;
        }
        int count = s1.size();

        int lo = 0, hi = 0;

        while (hi < s2.size()) {
            if (count == 0) return true;

            if (fMap.find(s2[hi]) == fMap.end()) {
                if (hi == lo) {
                    hi++;
                    lo++;
                    continue;
                }
                while (lo != hi) {
                    fMap[s2[lo]]++;
                    count++;
                    lo++;
                }
            }else {
                // if (fMap[s2[hi]] == 0) {
                //     while (fMap[s2[hi]] == 0) {
                //         fMap[s2[lo]]++;
                //         count++;
                //         lo++;
                //     }
                // }else {
                //     fMap[s2[hi]]--;
                //     hi++;
                //     count--;
                // }
                while (fMap[s2[hi]] == 0) {
                    fMap[s2[lo]]++;
                    count++;
                    lo++;
                }

                fMap[s2[hi]]--;
                hi++;
                count--;
            }
        }

        if (count == 0) return true;
        return false;
    }
};
