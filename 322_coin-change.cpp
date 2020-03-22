#include "util.h"

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> a(amount+1, amount+1);
        a[0] = 0;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = amount; j >= coins[i]; j--) {
                for (int k = 1; k <= j / coins[i]; k++) {
                    a[j] = min(a[j], a[j-k*coins[i]] + k);
                }
            }
        }
        return a[amount];
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        int ret = Solution().coinChange(nums, k);

        cout << ret << endl;
    }
    return 0;
}