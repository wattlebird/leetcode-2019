#include "util.h"

using namespace std;

class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<int> dp(k+1, 0);
        for(vector<int>& p: piles) {
            vector<int> cur = dp;
            int sum = 0;
            for(int j = 1; j <= p.size(); j++) {
                sum += p[j-1];
                for(int i = j; i <= k; i++) {
                    cur[i] = max(cur[i], sum + dp[i-j]);
                }
            }
            dp = cur;
        }
        return dp.back();
    }

};

int main() {
  vector<vector<int>> piles;
  Solution slu;
  piles = {
    {1,100,3},
    {7,8,9}
  };
  cout << slu.maxValueOfCoins(piles, 2) << endl;
  return 0;
}