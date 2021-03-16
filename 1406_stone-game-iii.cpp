#include "util.h"

using namespace std;

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int> dp(stoneValue.size() + 1, 0);
        vector<int> a = stoneValue, a2 = stoneValue;
        for(int i = 0; i < int(a.size() - 1); i++) {
            a2[i] += a[i+1];
        }
        if (a.size() >= 1) a2[a.size() - 1] = 0;
        vector<int> a3 = a2;
        for(int i = 0; i < int(a.size() - 2); i++) {
            a3[i] += a[i+2];
        }
        if (a.size() >= 2) a3[a.size() - 2] = 0;
        
        for(int i = a.size() - 1; i >= 0; i--) {
            dp[i] = a[i] - dp[i+1];
            if (i + 2 <= a.size()) dp[i] = max(dp[i], a2[i] - dp[i+2]);
            if (i + 3 <= a.size()) dp[i] = max(dp[i], a3[i] - dp[i+3]);
        }
        
        if (dp[0] > 0) return "Alice";
        else if (dp[0] < 0) return "Bob";
        else return "Tie";
    }
};

int main() {
    Solution slu;
    vector<int> a;
    a = {1};
    cout << slu.stoneGameIII(a) <<endl;
    return 0;
}