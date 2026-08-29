class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;
        int counter = s.size();

        for (const auto& c : s) {
            mp[c]++;
        }

        for (const auto& c : t) {
            if (mp.find(c) == mp.end() || mp[c] == 0) return false;

            mp[c]--;
            counter--;
        }

        if (counter == 0) return true;
        return false;
    }
};
