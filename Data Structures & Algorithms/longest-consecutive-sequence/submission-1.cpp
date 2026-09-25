class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        unordered_map<int, int> hashMap;

        int longest = INT_MIN;

        for (const int& num : nums) {
            if (hashMap.find(num) != hashMap.end()) continue;

            int length = 1;

            if (hashMap.find(num - 1) != hashMap.end()) {
                length += hashMap[num - 1];
            }

            if (hashMap.find(num + 1) != hashMap.end()) {
                length += hashMap[num + 1];
            }

            hashMap[num] = length;

            longest = max(longest, length);

            if (hashMap.find(num - 1) != hashMap.end()) {
                hashMap[num - hashMap[num - 1]] = length;
            }

            if (hashMap.find(num + 1) != hashMap.end()) {
                hashMap[num + hashMap[num + 1]] = length;
            }
        }

        return longest;
    }
};
