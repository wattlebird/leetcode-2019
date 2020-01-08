#include "util.h"
#include <map>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        if (s.size() == 0) return 0;
        map<char, int> G;
        int rtn = k+1;
        int d = s[0];
        for(int i = 0; i <= k; i++) {
            G[s[i]]++;
            if (G[d] < G[s[i]]) d = s[i];
        }
        for (int l = 0, r = k+2; r <= s.size(); r++) {
            G[s[r-1]]++;
            if (s[r-1] != d && G[s[r-1]] > G[d]) d = s[r-1];
            while (r-l-G[d] > k) {
                G[s[l++]]--;
                if (s[l-1] == d) {
                    for(auto p : G) {
                        if (p.second > G[d]) d = p.first;
                    }
                }
            }
            rtn = max(rtn, r-l);
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
        
        int ret = Solution().characterReplacement(s, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}