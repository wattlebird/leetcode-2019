#include "util.h"

using namespace std;

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> rtn;
        vector<TreeNode*> stack;
        TreeNode* cur = root;
        while(cur != nullptr) {
            while (cur != nullptr) {
                stack.push_back(cur);
                cur = cur -> left;
            }
            while (stack.back() -> right == nullptr || stack.back() -> right == cur) {
                cur = stack.back();
                stack.pop_back();
                rtn.push_back(cur -> val);
                if (stack.empty()) break;
            }
            cur = stack.empty() ? nullptr : stack.back() -> right;
        }
        return rtn;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        
        vector<int> ret = Solution().postorderTraversal(root);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}