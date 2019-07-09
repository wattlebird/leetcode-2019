#include "util.h"

using namespace std;

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *cur = head;
        ListNode *pre = nullptr;
        int len = 0;
        while (cur) {
            pre = cur;
            cur = cur -> next;
            len++;
        }
        if (len == 0 || k == 0) return head;
        pre -> next = head;
        cur = pre -> next;
        k = (len - k % len) % len;
        while (k--) {
            pre = cur;
            cur = cur -> next;
        }
        pre -> next = nullptr;
        return cur;
    }

};

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        ListNode* ret = Solution().rotateRight(head, k);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}