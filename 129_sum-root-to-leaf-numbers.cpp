#include "util.h"

using namespace std;

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return this -> sum;
    }
private:
    int sum = 0;
    void dfs(TreeNode* root, int prev) {
        if (root == nullptr) return;
        else {
            int cur = 10 * prev + root -> val;
            if (root -> left == nullptr && root -> right == nullptr) this->sum += cur;
            if (root -> left != nullptr) dfs(root -> left, cur);
            if (root -> right != nullptr) dfs(root -> right, cur);
        }
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        
        int ret = Solution().sumNumbers(root);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}