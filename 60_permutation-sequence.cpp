#include "util.h"

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        k--;
        vector<int> a(n, 1);
        vector<bool> used(128, false);
        string rtn;
        for(int i = n - 2; i >= 0; i--) {
            a[i] = a[i+1] * (n - i - 1);
        }
        for(int i = 0; i < n; i++) {
            int t = k/a[i];
            k %= a[i];
            for (char c = '1'; c < '1' + n; c++) {
                if (!used[c]) {
                    if (t == 0) {
                        rtn+=c;
                        used[c] = true;
                        break;
                    }
                    else t--;
                }
            }
        }
        return rtn;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        string ret = Solution().getPermutation(n, k);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}