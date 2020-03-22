#include "util.h"

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> a(2, vector<int>(amount+1, 0));
        for(int i = 0; i < coins.size(); i++) {
            if (coins[i] > amount) {
                a[i%2] = a[(i+1)%2];
                continue;
            }
            for(int j = 1; j <= amount; j++) {
                a[i%2][j] = a[(i+1)%2][j];
                if (j == coins[i]) a[i%2][j]++;
                else if (j > coins[i]) a[i%2][j] += a[i%2][j-coins[i]];
            }
        }
        return a[(coins.size()+1)%2].back();
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        int amount = stringToInteger(line);
        getline(cin, line);
        vector<int> coins = stringToIntegerVector(line);
        
        int ret = Solution().change(amount, coins);

        cout << ret << endl;
    }
    return 0;
}