#include "util.h"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        else if (prices.size() == 2) return max(0, prices[1] - prices[0]);
        vector<vector<int>> dp(3, vector<int>(prices.size()+1, 0));
        for(int i = 0; i < prices.size(); i++) {
            int j = i+1;
            dp[0][j] = i > 1 ? max(dp[0][i], dp[2][i]) : dp[0][i];
            dp[1][j] = i == 0 ? dp[0][i] - prices[i] : max(dp[0][i] - prices[i], dp[1][i]);
            dp[2][j] = i > 0 ? dp[1][i] + prices[i] : 0;
        }
        return max(dp[0][prices.size()], dp[2][prices.size()]);
    }
};

int main() {
    vector<int> prices;
    Solution slu;
    prices = {1,2,3,0,2};
    cout << slu.maxProfit(prices) <<endl;

    return 0;
}