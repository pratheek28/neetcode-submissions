class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> hashMap;

        for (int i = 0; i < numbers.size(); i++) {
            if (hashMap.find(target - numbers[i]) != hashMap.end()) {
                return {hashMap[target - numbers[i]] + 1, i + 1};
            }

            hashMap[numbers[i]] = i;
        }

        return {};
    }
};
