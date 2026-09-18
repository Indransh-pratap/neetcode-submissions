class Solution {
   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int dr[] = {1, 0, -1, 0};
        int dc[] = {0, 1, 0, -1};

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        int maxarea = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
                int ans = 0;
                while (!q.empty()) {
                    ans += 1;
                    int row = q.front().first;
                    int col = q.front().second;
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int newrow = dr[k] + row;
                        int newcol = dc[k] + col;

                        if (newrow < n && newrow >= 0 && newcol >= 0 && newcol < m &&
                            !vis[newrow][newcol] && grid[newrow][newcol] == 1) {
                            q.push({newrow, newcol});

                            vis[newrow][newcol] = 1;
                        }
                    }
                }
                maxarea = max(ans, maxarea);
            }
        }
        return maxarea;
    }
};
