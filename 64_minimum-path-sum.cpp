#include "util.h"

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n, 0);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (j != 0) {
                    if (i == 0) dp[j] = dp[j-1] + grid[i][j];
                    else dp[j] = min(dp[j-1], dp[j]) + grid[i][j];
                }
                else dp[j] += grid[i][j];
            }
        }
        return dp.back();
    }
};

int main() {
    vector<vector<int>> grid = {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };
    cout << Solution().minPathSum(grid) << endl;
    return 0;
}