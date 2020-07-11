#include "util.h"

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int ncol = matrix[0].size(), nrow = matrix.size();
        vector<vector<int>> acc(nrow+1, vector<int>(ncol+1, 0));
        for(int i = 1; i <= nrow; i++) {
            for(int j = 1; j <= ncol; j++) {
                acc[i][j] = acc[i-1][j] + acc[i][j-1] - acc[i-1][j-1];
                if (matrix[i-1][j-1] == '1') acc[i][j]++;
            }
        }
        vector<vector<int>> sqr(nrow+1, vector<int>(ncol+1, 0));
        int rtn = 0;
        for(int i = 1; i <= nrow; i++) {
            for(int j = 1; j <= ncol; j++) {
                int l = sqr[i-1][j-1];
                do {
                    int m = acc[i][j] - acc[i-1-l][j] - acc[i][j-1-l] + acc[i-1-l][j-1-l];
                    if (m == l*l + 2*l + 1) {sqr[i][j] = l+1; rtn = max(rtn, l+1); break;}
                } while (--l >= 0);
            }
        }
        return rtn*rtn;
    }
};

int main() {
    vector<vector<char>> matrix = {
        {'0','0','0','1'},
        {'1','1','0','1'},
        {'1','1','1','1'},
        {'0','1','1','1'},
        {'0','1','1','1'}
    };
    cout << Solution().maximalSquare(matrix) << endl;
    return 0;
}