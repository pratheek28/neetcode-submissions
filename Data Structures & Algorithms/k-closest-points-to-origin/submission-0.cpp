class Solution {
    struct PointCompare {
        bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.second > p2.second;
        }
    };

    int sqrtDist(int x, int y) {
        return x * x + y * y;
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, PointCompare> minHeap;

        vector<vector<int>> sol;

        for (int i = 0; i < points.size(); i++) {
            minHeap.push({i, sqrtDist(points[i][0], points[i][1])});
        }

        while (k != 0) {
            int idx = minHeap.top().first;
            sol.push_back(points[idx]);

            minHeap.pop();
            k--;
        }

        return sol;
    }
};
