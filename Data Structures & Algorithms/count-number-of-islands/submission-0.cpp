class Solution {
public:
    vector<vector<int>> directions = {{1,0}, {-1,0}, {0,-1}, {0, 1}};
    int result = 0;

    int numIslands(vector<vector<char>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] != '0') {
                    result++;
                    dfs(grid, r, c);
                }
            }
        }

        return result;
    }

    void dfs (vector<vector<char>>& grid, int r, int c) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == '0') {
            return;
        }

        grid[r][c] = '0';

        for (auto direction : directions) {
            dfs(grid, r + direction[0], c + direction[1]);
        }
    }


};
