#include "util.h"

using namespace std;

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        vector<int> bcc(piles.size() + 1, 0);
        for(int i = piles.size() - 1; i >= 0; i--) bcc[i] = bcc[i+1] + piles[i];
        vector<vector<int>> dp(piles.size() + 1, vector<int>(piles.size() + 1, 0));
        for(int i = piles.size() - 1; i >= 0; i--) {
            for(int m = 1; m <= piles.size(); m++) {
                for(int x = 1; x + i <= piles.size() && x <= m * 2; x++) {
                    int nm = max(m, x);
                    int j = i + x; // exclusive
                    dp[i][m] = max(dp[i][m], bcc[i] - dp[j][nm]);
                }
            }
        }
        return dp[0][1];
    }
};

int main() {
    Solution slu;

    vector<int> piles;
    piles = {2,7,9,4,4};
    cout << slu.stoneGameII(piles) << endl;
    piles = {1,2,3,4,5,100};
    cout << slu.stoneGameII(piles) << endl;
    return 0;
}