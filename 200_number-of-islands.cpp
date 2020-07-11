#include "util.h"

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        this->grid = grid;
        int m = grid.size();
        int n = grid[0].size();
        int rtn = 0;
        vis = vector<vector<bool>>(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {dfs(i, j); rtn++;}
            }
        }
        return rtn;
    }
private:
    vector<vector<bool>> vis;
    vector<vector<char>> grid;
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void dfs(int i, int j) {
        int m = vis.size();
        int n = vis[0].size();
        vis[i][j] = true;
        for(int e = 0; e < 4; e++) {
            int ii = i + dir[e][0];
            int jj = j + dir[e][1];
            if (ii >= 0 && ii < m && jj >= 0 && jj < n) {
                if (grid[ii][jj] == '1' && !vis[ii][jj]) dfs(ii, jj);
            }
        }
    }
};

int main() {
    string line;
    vector<vector<char>> arg;
    while (getline(cin, line)) {
        trimRightTrailingSpaces(line);
        if (line.size() == 0) {
            cout << Solution().numIslands(arg) << endl;
            arg.clear();
        } else {
            vector<char> c(line.begin(), line.end());
            arg.push_back(c);
        }
    }
    return 0;
}