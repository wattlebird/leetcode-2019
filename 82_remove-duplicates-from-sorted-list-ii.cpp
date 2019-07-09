#include "util.h"

using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode dummy(head->val - 1);
        ListNode *pre = &dummy;
        ListNode *cur = head;
        pre -> next = cur;

        while (cur) {
            if (cur -> next && cur -> next -> val == cur -> val) {
                while (cur -> next && cur -> next -> val == cur -> val) cur = cur -> next;
                pre -> next = cur -> next;
                cur = cur -> next;
            } else {
                pre = cur;
                cur = cur -> next;
            }
        }
        return dummy.next;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);
        
        ListNode* ret = Solution().deleteDuplicates(head);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}