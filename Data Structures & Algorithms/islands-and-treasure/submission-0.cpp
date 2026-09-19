class Solution {
   public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        int delrow[] = {1, -1, 0, 0};
        int delcol[] = {0, 0, 1, -1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                    vis[i][j] = 1;
                    dis[i][j] = 0;
                }
            }
        }



          while (!q.empty()) {
                    int row = q.front().first;
                    int col = q.front().second;
                    q.pop();
                    int dist = 0;
                    for (int k = 0; k < 4; k++) {
                        int newrow = delrow[k] + row;
                        int newcol = delcol[k] + col;
                        if (newrow >= 0 && newrow < n && newcol >= 0 && newcol < m &&
                            !vis[newrow][newcol] && grid[newrow][newcol] == INT_MAX) {
                            vis[newrow][newcol] = 1;

                            dis[newrow][newcol] = dis[row][col] + 1;

                            q.push({newrow, newcol});
                        }
                    }
                }
                

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
               if (grid[i][j] == INT_MAX) {
            grid[i][j] = dis[i][j];
        }
            }
        }
    }
};
