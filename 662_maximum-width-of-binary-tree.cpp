#include "util.h"

using namespace std;

typedef struct {
    TreeNode* node;
    int idx;
} Item;

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        int rtn = 1;
        queue<Item> Q;
        Q.push({root, 0});
        while (!Q.empty()) {
            vector<Item> row;
            while (!Q.empty()) {
                row.push_back(Q.front());
                Q.pop();
            }
            rtn = max(row.back().idx - row.front().idx + 1, rtn);
            int h = row.front().idx;
            for(Item itm: row) {
                if ((itm.node)->left != nullptr) Q.push({.node = (itm.node)->left, .idx = (itm.idx - h)*2});
                if ((itm.node)->right != nullptr) Q.push({.node = (itm.node)->right, .idx = (itm.idx - h)*2+1});
            }
        }
        return rtn;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        
        int ret = Solution().widthOfBinaryTree(root);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}