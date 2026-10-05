class Solution {
    int destroy(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] == 0) return 0;

        grid[i][j] = 0;

        int top = destroy(grid, i - 1, j);
        int bot = destroy(grid, i + 1, j);
        int left = destroy(grid, i, j - 1);
        int right = destroy(grid, i, j + 1);

        return 1 + top + bot + left + right;

    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    res = max(res, destroy(grid, i, j));
                }
            }
        }

        return res;
    }
};
