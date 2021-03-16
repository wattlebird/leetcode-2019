#include "util.h"

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(2, 0));
        // take first item
        dp[0][1] = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = nums[i] + dp[i-1][0];
        }
        int can = dp.back()[0];
        fill(dp.begin(), dp.end(), vector<int>(2, 0));
        // don't take first item
        for(int i = 1; i < nums.size(); i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = nums[i] + dp[i-1][0];
        }
        int rst = max(can, max(dp.back()[0], dp.back()[1]));
        return rst;
    }
};

int main() {
    Solution slu;
    vector<int> nums;
    nums = {2,3,2};
    cout << slu.rob(nums) << endl;
    nums = {1,2,3,1};
    cout << slu.rob(nums) << endl;
    nums = {0};
    cout << slu.rob(nums) << endl;
}