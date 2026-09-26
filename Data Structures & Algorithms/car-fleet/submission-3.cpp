class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars(position.size(), {0,0});

        for (int i = 0; i < position.size(); i++) {
            cars[i] = {position[i], speed[i]};
        }

        sort(cars.rbegin(), cars.rend());

        vector<double> st;

        for(const auto& p : cars) {
            st.push_back(static_cast<double>(target - p.first) / p.second);

            if (st.size() >= 2 && st.back() <= st[st.size() - 2]) {
                st.pop_back();
            }
        }

    
        return st.size();
    }
};
