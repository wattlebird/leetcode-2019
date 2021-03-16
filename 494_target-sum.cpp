#include "util.h"

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if (S == 0) return 0;
        int sum = 0;
        for(auto n: nums) sum += n;
        if ((sum + S) & 0x1) return 0;
        sum = (S > 0 ? sum - S : sum + S) / 2;
        vector<int> dp(sum + 1, 0);
        dp[sum] = 1;
        for(auto n: nums) {
            for(int w = 0; w <= sum - n; w++) {
                dp[w] += dp[w + n];
            }
        }
        return dp[0];
    }
};

int main() {
    Solution slu;
    vector<int> nums;
    nums = {1,1,1,1,1};
    cout << slu.findTargetSumWays(nums, 4) << endl;
    return 0;
}