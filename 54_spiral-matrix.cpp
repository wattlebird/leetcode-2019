#include "util.h"

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int h = matrix.size();
        int w = matrix[0].size();
        vector<int> rtn;
        int cnt = 0;
        while (cnt < (min(h, w) + 1) / 2) {
            int i = cnt, j = cnt;
            if (w - cnt * 2 == 1) {
                while (j < h - cnt) rtn.push_back(matrix[j++][i]);
                break;
            }
            if (h - cnt * 2 == 1) {
                while (i < w - cnt) rtn.push_back(matrix[j][i++]);
                break;
            }
            while (i < w - cnt - 1) rtn.push_back(matrix[j][i++]);
            while (j < h - cnt - 1) rtn.push_back(matrix[j++][i]);
            if (i != cnt && j != cnt) {
                while (i > cnt) rtn.push_back(matrix[j][i--]);
                while (j > cnt) rtn.push_back(matrix[j--][i]);
            }
            cnt++;
        }
        return rtn;
    }
};

int main() {
    Solution slu;
    vector<vector<int>> ma;
    ma = {
        {1,2,3,4},
        {5,6,7,8},
        {9,0,1,2}
    };
    cout << integerVectorToString(slu.spiralOrder(ma)) << endl;
    return 0;
}