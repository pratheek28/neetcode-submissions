class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for (const auto& str : strs) {
            res += to_string(str.size());
            res += ",";
        }

        res += "#";

        for (const auto& str: strs) {
            res += str;
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        queue<int> sizes;

        int i = 0;

        while (i < s.size()) {
            if (s[i] == '#') break;
            int hi = i + 1;
            while (s[hi] != ',') {
                hi++;
            }

            sizes.push(stoi(s.substr(i, hi - i)));
            i = hi;
            i++;
        }

        i++;

        while (!sizes.empty()) {
            int currSize = sizes.front();
            sizes.pop();

            if (currSize == 0) res.push_back("");
            else {
                res.push_back(s.substr(i, currSize));
                i += currSize;
            }
        }

        return res;
    }
};
