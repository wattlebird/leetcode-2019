#include "util.h"

using namespace std;

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<int> range(n, 0);
        for (int i = 1; i <= n; i++) range[i-1] = i;
        return helper(range.begin(), range.end());
    }
private:
    vector<TreeNode*> helper(vector<int>::const_iterator b, vector<int>::const_iterator e) {
        if (b == e) return vector<TreeNode*>{nullptr};
        
        vector<TreeNode*> rtn;
        for (vector<int>::const_iterator i = b; i != e; i++) {
            vector<TreeNode*> left = helper(b, i);
            vector<TreeNode*> right = helper(i+1, e);
            for(TreeNode* leftNode: left) {
                for (TreeNode* rightNode: right) {
                    TreeNode* cur = new TreeNode(*i);
                    cur -> left = leftNode;
                    cur -> right = rightNode;
                    rtn.push_back(cur);
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
        
        vector<TreeNode*> ret = Solution().generateTrees(n);

        for(TreeNode* x: ret) {
            cout << treeNodeToString(x) << endl;
        }
    }
    return 0;
}