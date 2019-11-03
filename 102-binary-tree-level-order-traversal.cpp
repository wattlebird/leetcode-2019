#include <vector>
#include "util.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> rtn;
        dfs(root, rtn, 1);
        return rtn;
    }

private:
    void dfs(TreeNode* node, vector<vector<int>>& rec, int level) {
        if (node == nullptr) return;
        if (rec.size() < level) rec.push_back(vector<int>());
        rec[level - 1].push_back(node -> val);
        dfs(node -> left, rec, level + 1);
        dfs(node -> right, rec, level + 1);
    }
};