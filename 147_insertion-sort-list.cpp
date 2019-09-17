#include "util.h"

using namespace std;

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *pre = &dummy, *cur = head;
        while (cur != nullptr) {
            ListNode *nxt = cur -> next;
            if (nxt != nullptr && nxt -> val < cur -> val) {
                ListNode *ins = dummy.next;
                pre = &dummy;
                while (ins -> val <= nxt -> val) {
                    ins = ins -> next;
                    pre = pre -> next;
                }
                cur -> next = nxt -> next;
                pre -> next = nxt;
                nxt -> next = ins;
            } else cur = cur -> next;
        }
        return dummy.next;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);
        
        ListNode* ret = Solution().insertionSortList(head);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}