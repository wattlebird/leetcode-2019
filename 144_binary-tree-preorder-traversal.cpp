#include "util.h"

using namespace std;

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> rtn;
        vector<TreeNode*> stack;
        TreeNode* cur = root;
        while(cur != nullptr) {
            while (cur != nullptr) {
                rtn.push_back(cur -> val);
                stack.push_back(cur);
                cur = cur -> left;
            }
            do {
                cur = stack.back();
                stack.pop_back();
            } while(cur -> right == nullptr && !stack.empty());
            cur = cur -> right;
        }
        return rtn;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        
        vector<int> ret = Solution().preorderTraversal(root);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}