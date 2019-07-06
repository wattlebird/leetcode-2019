#include <iostream>
#include <string>
#include <vector>
#include "util.h"

using namespace std;

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (root == nullptr) return false;
        vector<int> arr;
        traversal(root, arr);
        int i = 0, j = arr.size() - 1;
        while(i < j) {
            if (arr[i] + arr[j] == k) {
                return true;
            } else if (arr[i] + arr[j] < k) i++;
            else j--;
        }
        return false;
    }
    void traversal(TreeNode* root, vector<int>& arr) {
        if (root == nullptr) return;
        traversal(root -> left, arr);
        arr.push_back(root -> val);
        traversal(root -> right, arr);
        return;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        bool ret = Solution().findTarget(root, k);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}