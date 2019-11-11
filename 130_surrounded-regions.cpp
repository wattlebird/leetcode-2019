#include "util.h"

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {

        if (board.size() <= 0 || board[0].size() <= 0) return;
        const int h = board.size();
        const int w = board[0].size();
        vector<bool> vis(h*w, false);
        for (size_t i = 0; i != h; i++) for (size_t j = 0; j != w; j++) {
            vis[j+i*w] = board[i][j] == 'X' ? true : false;
        }
        vector<bool> origin(vis);
        queue<int> Q;
        for (size_t i = 0; i != w; i++) if (board[0][i] == 'O') Q.push(i);
        for (size_t i = 0; i != w; i++) if (board[h-1][i] == 'O') Q.push(w*(h-1) + i);
        for (size_t i = 1; i < h-1; i++) if (board[i][0] == 'O') Q.push(w*i);
        for (size_t i = 1; i < h-1; i++) if (board[i][w-1] == 'O') Q.push(w*(i+1)-1);
        while (!Q.empty()) {
            int cur = Q.front(); Q.pop();
            if (vis[cur]) continue;
            vis[cur] = true;
            if (cur + w < h * w && !vis[cur+w]) Q.push(cur+w);
            if (cur - w >= 0 && !vis[cur-w]) Q.push(cur-w);
            if ((cur + 1) % w != 0 && !vis[cur + 1]) Q.push(cur + 1);
            if (cur % w != 0 && !vis[cur - 1]) Q.push(cur - 1);
        }
        for (int idx = 0; idx != vis.size(); idx++) {
            if (!vis[idx] && !origin[idx]) {
                int i = idx / w;
                int j = idx % w;
                board[i][j] = 'X';
            }
        }
        return;
    }
};
