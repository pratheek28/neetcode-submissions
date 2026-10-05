class Solution {
    void destroy(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] == '0') return;

        grid[i][j] = '0';

        destroy(grid, i - 1, j);
        destroy(grid, i + 1, j);
        destroy(grid, i, j - 1);
        destroy(grid, i, j + 1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    res++;
                    destroy(grid, i, j);
                }
            }
        }

        return res;
    }
};
