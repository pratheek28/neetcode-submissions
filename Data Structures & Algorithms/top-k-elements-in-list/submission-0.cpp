class Solution {
    struct ComparePairs {
        bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.second < p2.second;
        }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for (const auto& num : nums) {
            mp[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, ComparePairs> maxHeap;

        for (const auto& p : mp) {
            maxHeap.push({p.first, p.second});
        }

        vector<int> sol;

        while (k != 0) {
            sol.push_back(maxHeap.top().first);
            maxHeap.pop();
            k--;
        }

        return sol;
    }
};
