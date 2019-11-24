#include "util.h"

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if (n == 0) return 0;
        vector<vector<int>> a(n+1, vector<int>(n+1, 0));
        for (int b = 1; b <= n; b++) a[b][b] = 1;
        for (int step = 1; step <= n-1; step++) {
            for (int b = 1; b + step <= n; b++) {
                int e = b + step;
                int cnt = a[b+1][e] + a[b][e-1];
                for (int m = b+1; m <= e-1; m++) {
                    cnt += a[b][m-1] * a[m+1][e];
                }
                a[b][e] = cnt;
            }
        }
        return a[1][n];
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().numTrees(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}