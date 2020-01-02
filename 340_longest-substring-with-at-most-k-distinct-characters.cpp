#include "util.h"

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int d = 0, rtn = 0;
        int cnt[128] = {0};
        for(int l = 0, r = 1; r <= s.size(); r++) {
            if (cnt[s[r-1]]++ == 0) d++;
            if (d <= k) rtn = max(rtn, r - l);
            else {
                while (l <= r && d > k) {
                    if (--cnt[s[l++]] == 0) d--;
                }
                if (d <= k) rtn = max(rtn, r - l);
            }
        }
        return rtn;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        int ret = Solution().lengthOfLongestSubstringKDistinct(s, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}