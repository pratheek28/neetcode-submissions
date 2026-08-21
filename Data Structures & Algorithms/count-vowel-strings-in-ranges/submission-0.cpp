class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> res;

        for (int i = 0; i < queries.size(); i++) {
            int start = queries[i][0];
            int end = queries[i][1];

            int num = 0;

            while (start <= end) {
                string word = words[start];
                if ((word[0] == 'a' || word[0] == 'e' || word[0] == 'i' ||word[0] == 'o' || word[0] == 'u') && (word[word.size() - 1] == 'a' || word[word.size() - 1] == 'e' || word[word.size() - 1] == 'i' ||word[word.size() - 1] == 'o' || word[word.size() - 1] == 'u')) {
                    num++;
                }
                start++;
            }

            res.push_back(num);
        }

        return res;
        
    }
};