#include "util.h"

using namespace std;

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        acc = vector<int>(piles.size()+1, 0);
        dp = vector<vector<vector<int>>>(acc.size(), vector<vector<int>>(acc.size(), vector<int>(2, -acc.back())));
        for(int i = 1; i <= piles.size(); i++) acc[i] = acc[i-1] + piles[i-1];
        int r = dfs(1, 0, 0, 0, 0);
        return (acc.back() + r) / 2;
    }
private:
    vector<int> acc;
    vector<vector<vector<int>>> dp;
    int dfs(int m, int i, int a, int b, int t) {
        if (i == acc.size() - 1) return t == 0 ? a - b : b - a;
        int rtn = 0 - acc.back();
        for(int j = 1; j <= 2 * m & j + i < acc.size(); j++) {
            int nm = max(m, j);
            int na = t == 0 ? a + acc[j+i] - acc[i] : a;
            int nb = t == 0 ? b : b + acc[j+i] - acc[i];
            rtn = max(rtn, -dfs(nm, i+j, na, nb, t ^ 1));
        }
        return rtn;
    }
};

int main() {
    Solution slu;
    vector<int> a = {1,2,3,4,5,100};
    cout << slu.stoneGameII(a) <<endl;
}