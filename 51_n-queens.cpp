#include "util.h"

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        cols = n;
        stack = vector<int>(n, -1);
        dfs(0, 0, 0, 0);
        return this->rtn;
    }
    
private:
    int cols;
    vector<int> stack;
    vector<vector<string>> rtn;
    
    void dfs(int depth, int vmask, int lmask, int rmask) {
        int mask = ((1 << cols) - 1) & (lmask | rmask | vmask);
        for(int i = 0; i < cols; i++) {
            if (((0x1 << i) & mask) == 0) {
                stack[depth] = i;
                if (depth == cols-1) {
                    yield();
                } else {
                    dfs(depth + 1, (vmask | (0x1 << i)), (lmask | (0x1 << i)) << 1, (rmask | (0x1 << i)) >> 1);
                }
            }
        }
    }
    
    void yield() {
        vector<string> rst;
        for(int i = 0; i < cols; i++) {
            string row = string(cols, '.');
            row[stack[i]] = 'Q';
            rst.push_back(row);
        }
        rtn.push_back(rst);
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        int nums = stringToInteger(line);
        
        auto ret = Solution().solveNQueens(nums);

        for(auto r: ret) {
            string out;
            out += "[";
            for(string s:r) {
                out += s;
                out += ",";
            }
            out[out.size() - 1] = ']';
            cout << out << endl;
        }
    }
    return 0;
}