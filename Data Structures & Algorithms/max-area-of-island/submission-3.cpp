class Solution {
public:
    vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maximum = 0;

        for (int r = 0 ; r < grid.size() ; r ++) {
            for (int c = 0; c < grid[0].size() ; c ++) {
                if (grid[r][c] == 1) {
                    dfs (grid, r, c, maximum);
                }
            }
        }
        return maximum;
        
    }

    int dfs (vector<vector<int>>& grid, int r, int c, int& maximum) {
        if (r >= grid.size() || r < 0 || c >= grid[0].size() || c < 0 || grid[r][c] == 0) {
            return 0;
        }

        
        grid[r][c] = 0;
        int area = 1;

        for (auto direction : directions) {
            area += dfs (grid, r + direction[0], c + direction[1], maximum);
        }
        maximum = max(maximum, area);

        return area;

    }
};
