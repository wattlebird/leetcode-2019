#include "util.h"

using namespace std;

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummy = new ListNode(0), *other = new ListNode(0);
        dummy -> next = head;
        ListNode *pre = dummy, *cur = head, *arc = other;
        while(cur != nullptr) {
            if (cur->val < x) {
                pre -> next = cur -> next;
                arc -> next = cur;
                cur -> next = nullptr;
                arc = cur;
                cur = pre -> next;
            } else {
                pre = cur;
                cur = cur -> next;
            }
        }
        arc -> next = dummy -> next;
        ListNode *rtn = other -> next;
        delete other, dummy;
        return rtn;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);
        getline(cin, line);
        int x = stringToInteger(line);
        
        ListNode* ret = Solution().partition(head, x);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}