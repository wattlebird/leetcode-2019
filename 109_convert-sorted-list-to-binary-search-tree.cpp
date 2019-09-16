#include "util.h"

using namespace std;

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return dfs(head, nullptr);
    }
private:
    TreeNode* dfs(ListNode* head, ListNode* tail) {
        if (head == nullptr || head == tail) return nullptr;
        ListNode dummy(0);
        dummy.next = head;
        ListNode *slow = &dummy, *fast = &dummy;
        while(fast != tail) {
            slow = slow -> next;
            fast = fast -> next;
            if (fast != tail) fast = fast -> next;
        }
        TreeNode *root = new TreeNode(slow -> val);
        root->left = dfs(head, slow);
        root->right = dfs(slow -> next, fast);
        return root;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);
        
        TreeNode* ret = Solution().sortedListToBST(head);

        string out = treeNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}