#include "util.h"

using namespace std;

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.size() <= 0 || rooms[0].size() <= 0) return;
        nr = rooms.size(), nc = rooms[0].size();
        const int inf = 2147483647;
        vector<int> gates;
        for(int r = 0; r < rooms.size(); r++) {
            for(int c = 0; c < rooms[0].size(); c++) {
                if (rooms[r][c] == 0) gates.push_back(r*nc+c);
            }
        }
        if (gates.size() == 0) return;
        vector<queue<int>> Qs(gates.size());
        for(int i = 0; i < gates.size(); i++) Qs[i].push(gates[i]);
        int depth = 0;
        while (any_of(Qs.begin(), Qs.end(), [](const queue<int>& Q){return !Q.empty();})) {
            depth++;
            for(queue<int>& Q: Qs) {
                vector<int> step;
                while (!Q.empty()) {step.push_back(Q.front()); Q.pop();}
                for(int u: step) {
                    int uc = ic(u), ur = ir(u);
                    for(int i = 0; i < 4; i++) {
                        int vc = dir[i][0]+uc, vr = dir[i][1]+ur;
                        if (vc >= 0 && vc < nc && vr >= 0 && vr < nr) {
                            if (rooms[vr][vc] == inf) { rooms[vr][vc] = depth; Q.push(vr*nc+vc); }
                            else if (rooms[vr][vc] == -1) continue;
                            else rooms[vr][vc] = min(rooms[vr][vc], depth);
                        }
                    }
                }
            }
        }
        return;
    }
private:
    int nc, nr;
    int ic(int x) { return x%nc;}
    int ir(int x) { return x/nc;}
    const vector<vector<int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};

int main() {
    vector<vector<int>> room = {{2147483647,-1,0,2147483647},{2147483647,2147483647,2147483647,-1},{2147483647,-1,2147483647,-1},{0,-1,2147483647,2147483647}};
    Solution().wallsAndGates(room);
    return 0;


}