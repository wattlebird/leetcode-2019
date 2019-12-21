#include "util.h"

using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() <= 0) return nullptr;
        int i = inorder.size() - 1;
        int j = postorder.size() - 1;
        vector<TreeNode*> stack;
        TreeNode* root = new TreeNode(postorder[j]);
        stack.push_back(root);
        while (j >= 0) {
            while (stack.back() -> val != inorder[i]) {
                stack.push_back(new TreeNode(postorder[--j]));
            }
            TreeNode* child = stack.back();
            stack.pop_back();
            while (i>0 && stack.back() -> val == inorder[i-1]) {
                stack.back() -> right = child;
                i--;
            }
            if (j > 0) {
                TreeNode* nxt = new TreeNode(postorder[--j]);
                child -> left = nxt;
                stack.push_back(nxt);
            }
        }
    }
};