#include <functional>
#include "util.h"

using namespace std;

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> rst;
        vector<TreeNode*> stack;
        if (root == nullptr) return true;
        TreeNode* cur = root;
        while(cur != nullptr) {
            while(cur != nullptr) {stack.push_back(cur); cur = cur->left;}
            cur = stack.back();
            stack.pop_back();
            rst.push_back(cur->val);
            while(cur->right == nullptr && !stack.empty()) {
                cur = stack.back();
                rst.push_back(cur->val);
                stack.pop_back();
            }
            cur = cur->right;
        }
        for(size_t i = 1; i < rst.size(); i++){
            if (rst[i-1] >= rst[i]) return false;
        }
        return true;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        
        bool ret = Solution().isValidBST(root);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}