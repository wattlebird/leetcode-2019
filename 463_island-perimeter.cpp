#include "util.h"

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        queue<pair<int, int>> Q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    Q.push(pair<int, int>(i, j));
                    break;
                }
            }
            if (!Q.empty()) break;
        }
        if (Q.empty()) return 0;
        
        int rtn = 0;
        while (!Q.empty()) {
            pair<int, int> u = Q.front();
            Q.pop();
            if (vis[u.first][u.second]) continue;
            int k = 0;
            vis[u.first][u.second] = true;
            for(int d = 0; d < 4; d++) {
                int x = u.first + dir[d][0];
                int y = u.second + dir[d][1];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    if (grid[x][y] == 1 && !vis[x][y]) {
                        Q.push(pair<int, int>(x, y));
                    }
                    if (vis[x][y]) {
                        k++;
                    }
                }
            }
            rtn += (4-2*k);
        }
        return rtn;
    }
private:
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int m, n;
};

int main() {
    Solution slu;
    vector<vector<int>> a = {
        {0,1,0,0},
        {1,1,1,0},
        {0,1,0,0},
        {1,1,0,0}
    };
    cout << slu.islandPerimeter(a) << endl;
    a = {
        {1,1},
        {1,1},
    };
    cout << slu.islandPerimeter(a) << endl;
    a = {
        {1,1,0},
        {1,1,1},
    };
    cout << slu.islandPerimeter(a) << endl;
    return 0;
}