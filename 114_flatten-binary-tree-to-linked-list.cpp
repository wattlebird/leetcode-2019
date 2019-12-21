#include "util.h"

using namespace std;

class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr || (root -> left == nullptr && root -> right == nullptr)) return;
        TreeNode* right = root->right;
        TreeNode* left = root->left;
        if (left != nullptr) {
            while(left -> right != nullptr) left = left -> right;
            root -> right = root -> left;
            left -> right = right;
            root -> left = nullptr;
        }
        flatten(root -> right);
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        
        Solution().flatten(root);

        string out = treeNodeToString(root);
        cout << out << endl;
    }
    return 0;
}