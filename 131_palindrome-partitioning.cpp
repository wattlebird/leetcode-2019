#include "util.h"

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        for(int i = 0; i < s.size(); i++) {
            dp[i][i] = true;
            if (i + 1 < s.size() && s[i] == s[i+1]) dp[i][i+1] = true;
        }
        for(int step = 2; step < s.size(); step++) for(int i = 0; i + step < s.size(); i++) {
            dp[i][i+step] = dp[i+1][i+step-1] && s[i] == s[i+step];
        }
        
        vector<vector<vector<string>>> slu(s.size());
        for(int j = 0; j < s.size(); j++) {
            vector<vector<string>> a;
            for(int i = j; i >= 0; i--) {
                if (dp[i][j]) {
                    string str = s.substr(i, j - i + 1);
                    if (i > 0) {
                        vector<vector<string>> p = slu[i-1];
                        for(vector<string> t: p) {
                            t.push_back(str);
                            a.push_back(t);
                        }
                    } else {
                        a.push_back({str});
                    }
                }
            }
            slu[j] = a;
        }
        return slu.back();
    }
};

int main() {
    Solution slu;
    auto rtn = slu.partition("aab");
    return 0;
}