#include "util.h"

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        target = word;
        G = board;
        m = board.size();
        n = board[0].size();
        vis = vector<vector<bool>>(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) {
            bool rtn = dfs(0, i, j);
            if (rtn) return true;
        }
        return false;
    }
private:
    vector<vector<bool>> vis;
    vector<vector<char>> G;
    int m, n;
    string target;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    bool dfs(int depth, int i, int j) {
        vis[i][j] = true;
        if (G[i][j] != target[depth]) {vis[i][j] = false; return false;}
        if (depth + 1 == target.size()) return true;
        for(int d = 0; d < 4; d++) {
            int ii = i + dir[d][0];
            int jj = j + dir[d][1];
            if (ii >= 0 && ii < m && jj >= 0 && jj < n && !vis[ii][jj]) {
                bool rtn = dfs(depth+1, ii, jj);
                if (rtn) return true;
            }
        }
        vis[i][j] = false;
        return false;
    }
};

int main() {
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    cout << Solution().exist(board, "ABCCED") << endl;
    cout << Solution().exist(board, "SEE") << endl;
    cout << Solution().exist(board, "ABCB") << endl;
    return 0;
}