#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        
        // Mark guards as 1
        for (auto &g : guards)
            grid[g[0]][g[1]] = 1;
        
        // Mark walls as 2
        for (auto &w : walls)
            grid[w[0]][w[1]] = 2;
        
        // Directions: up, down, left, right
        vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        
        // Simulate guard vision
        for (auto &g : guards) {
            int r = g[0], c = g[1];
            for (auto &d : dirs) {
                int x = r + d[0], y = c + d[1];
                while (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != 1 && grid[x][y] != 2) {
                    if (grid[x][y] == 0)
                        grid[x][y] = 3; // mark as guarded
                    x += d[0];
                    y += d[1];
                }
            }
        }
        
        // Count unguarded cells
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    count++;
            }
        }
        
        return count;
    }
};
