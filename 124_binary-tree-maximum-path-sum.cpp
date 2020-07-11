#include "util.h"

using namespace std;

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        rtn = root->val;
        dfs(root);
        return rtn;
    }
private:
    int rtn;
    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;
        int lsum = dfs(root -> left);
        int rsum = dfs(root -> right);
        rtn = max(rtn, root -> val + max(lsum, 0) + max(rsum, 0));
        return max(max(lsum, 0), max(rsum, 0)) + root -> val;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        
        int ret = Solution().maxPathSum(root);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}