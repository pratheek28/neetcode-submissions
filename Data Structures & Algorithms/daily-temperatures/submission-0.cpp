class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);

        stack<pair<int, int>> st;

        for (int i = 0; i < temperatures.size(); i++) {
            while (!st.empty() && st.top().first < temperatures[i]) {
                int idx = st.top().second;

                res[idx] = i - idx;
                st.pop();
            }

            st.push({temperatures[i], i});
        }

        return res;
    }
};
