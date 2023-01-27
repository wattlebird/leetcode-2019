#include "util.h"

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        string rtn;
        int a[128] = {0};
        if (s.size() < t.size()) return rtn;
        for(int i = 0; i < t.size(); i++) {
            a[t[i]]++;
        }
        int pre = 0, nxt = 0, cnt = t.size(), d = s.size() + 1;
        while(nxt < s.size()) {
            char cn = s[nxt++];
            if (a[cn]-- > 0) cnt--;
            while (pre < nxt && cnt == 0) {
                if (nxt - pre < d) {
                    d = nxt - pre;
                    rtn = s.substr(pre, nxt - pre);
                }
                char cp = s[pre++];
                if (a[cp]++ == 0) cnt++;
            }
        }
        return rtn;
    }
};

int main() {
    Solution slu;
    cout << slu.minWindow("ADOBECODEBANC", "ABC") << endl;
    cout << slu.minWindow("a", "aa") << endl;
    cout << slu.minWindow("aa", "a") << endl;
    cout << slu.minWindow("a", "a") << endl;
    cout << slu.minWindow("cabwefgewcwaefgcf", "cae") << endl;

    return 0;
}