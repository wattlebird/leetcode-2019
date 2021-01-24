#include "util.h"
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode* pre = &dummy, *cur = head, *pre1, *pre2, *t, *s, *p;
        int i = 1, j;
        while (cur != nullptr) {
            if (i == k) {
                pre1 = pre;
            }
            pre = cur;
            cur = cur->next;
            i++;
        }
        j = i - k;
        if (j == i) return head;
        bool flag = k < j;
        pre = &dummy, cur = head;
        while (j != 1) {
            pre = cur;
            cur = cur -> next;
            j--;
        }
        pre2 = pre;
        if (!flag) swap(pre1, pre2);
        if (pre1 -> next == pre2) {
            t = pre1 -> next;
            pre1 -> next = pre2 -> next;
            t -> next = pre2 -> next -> next;
            pre1 -> next -> next = t;
        } else {
            swap(pre1 -> next -> next, pre2 -> next -> next);
            swap(pre1 -> next, pre2 -> next);
        }
        return dummy.next;
    }
};

int main() {
    Solution slu;
    ListNode * head = stringToListNode("[1,2,3]");
    cout << listNodeToString(slu.swapNodes(head, 1)) << endl;
    head = stringToListNode("[1,2,3,4,5]");
    cout << listNodeToString(slu.swapNodes(head, 2)) << endl;
    head = stringToListNode("[7,9,6,6,7,8,3,0,9,5]");
    cout << listNodeToString(slu.swapNodes(head, 5)) << endl;
    head = stringToListNode("[1]");
    cout << listNodeToString(slu.swapNodes(head, 1)) << endl;
    head = stringToListNode("[1,2]");
    cout << listNodeToString(slu.swapNodes(head, 1)) << endl;
    head = stringToListNode("[1,2,3]");
    cout << listNodeToString(slu.swapNodes(head, 2)) << endl;
    return 0;
}