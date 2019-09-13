#include "util.h"

using namespace std;

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == nullptr) return head;
        ListNode *dummy = new ListNode(0);
        dummy -> next = head;
        ListNode *pre = dummy, *cur = dummy ;
        int cnt = 0;
        while (cnt != m - 1) { pre = pre -> next; cur = cur -> next; cnt++; }
        while (cnt <= n) { cur = cur -> next; cnt++; }
        ListNode *nxt;
        cnt = n - m + 1;
        while (cnt--) {
            nxt = pre -> next;
            pre -> next = nxt -> next;
            nxt -> next = cur;
            cur = nxt;
        }
        pre -> next = cur;
        nxt = dummy->next;
        delete dummy;
        return nxt;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);
        getline(cin, line);
        int m = stringToInteger(line);
        getline(cin, line);
        int n = stringToInteger(line);
        
        ListNode* ret = Solution().reverseBetween(head, m, n);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}