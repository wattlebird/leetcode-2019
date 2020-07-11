#include "util.h"

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int dp[text2.size()+1][text1.size()+1] = {{0}};
        for(int i = 1; i <= text2.size(); i++) {
            for(int j = 1; j <= text1.size(); j++) {
                int prev = max(dp[i-1][j], dp[i][j-1]);
                if (text2[i-1] == text1[j-1]) prev = max(prev, dp[i-1][j-1]+1);
                dp[i][j] = prev;
            }
        }
        return dp[text2.size()][text1.size()];
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        string text1 = stringToString(line);
        getline(cin, line);
        string text2 = stringToString(line);
        
        int ret = Solution().longestCommonSubsequence(text1, text2);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}