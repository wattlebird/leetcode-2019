#include "util.h"

using namespace std;

class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        vector<vector<int>> dp(stones.size(), vector<int>(stones.size(), 0));
        vector<int> acc(stones.size() + 1, 0);
        for(int i = 0; i < stones.size(); i++) acc[i+1] = acc[i] + stones[i];
        for(int step = 1; step < stones.size(); step++) {
            for(int i = 0; i + step < stones.size(); i++) {
                dp[i][i+step] = max(acc[i+step+1] - acc[i+1] - dp[i+1][i+step], acc[i+step] - acc[i] - dp[i][i+step-1]);
            }
        }
        return dp[0][stones.size() - 1];
    }
};

int main() {
    Solution slu;
    vector<int> stones;
    stones = {5,3,1,4,2};
    cout << slu.stoneGameVII(stones) <<endl;
    stones = {7,90,5,1,100,10,10,2};
    cout << slu.stoneGameVII(stones) <<endl;
    return 0;
}