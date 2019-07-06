#include "util.h"

using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *base, *merge, *cur, *prev;
        if (l1 == nullptr) return l2;
        else if (l2 == nullptr) return l1;
        if (l1 -> val <= l2 -> val) {
            base = l1;
            merge = l2;
        } else {
            base = l2;
            merge = l1;
        }
        cur = merge;
        prev = base;
        while (cur != nullptr) {
            if (prev -> next != nullptr) {
                if (prev -> next -> val > cur -> val) {
                    merge = cur -> next;
                    cur -> next = prev -> next;
                    prev -> next = cur;
                    cur = merge;
                }
                prev = prev -> next;
            } else {
                prev -> next = cur;
                break;
            }
        }
        return base;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* l1 = stringToListNode(line);
        getline(cin, line);
        ListNode* l2 = stringToListNode(line);
        
        ListNode* ret = Solution().mergeTwoLists(l1, l2);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}