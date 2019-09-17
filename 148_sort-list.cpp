#include "util.h"

using namespace std;

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return qsort(head, nullptr);
    }
private:
    ListNode* qsort(ListNode* head, ListNode* tail) {
        if (head == tail || head -> next == tail) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode *start = &dummy, *pre = head, *cur = head -> next;
        bool flag = false;
        while(cur && cur != tail) {
            if (cur -> val < head -> val) {
                flag = true;
                pre -> next = cur -> next;
                cur -> next = start -> next;
                start -> next = cur;
                cur = pre -> next;
            } else {
                pre = cur;
                cur = cur -> next;
                if (cur && pre -> val > cur -> val) flag = true;
            }
        }
        
        if (!flag) return head;
        head -> next = qsort(head->next, nullptr);
        return qsort(dummy.next, head);
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);
        
        ListNode* ret = Solution().sortList(head);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}