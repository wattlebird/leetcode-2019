#include "util.h"

using namespace std;

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        TreeNode *left = root, *right = root;
        return compare(left, right);
    }

private:
    bool compare(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) return true;
        else if ((left == nullptr) != (right == nullptr)) return false;
        else return (left -> val == right -> val) && compare(left -> left, right -> right) && compare(right -> left, left -> right);
    }
};