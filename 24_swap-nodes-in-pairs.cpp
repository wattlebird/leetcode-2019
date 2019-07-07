#include "util.h"

using namespace std;

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy -> next = head;
        ListNode *cur = dummy;
        while(cur -> next != nullptr && cur -> next -> next != nullptr) {
            ListNode *n1 = cur -> next;
            ListNode *n2 = n1 -> next;
            cur -> next = n2;
            n1 -> next = n2 -> next;
            n2 -> next = n1;
            cur = n1;
        }
        cur = dummy -> next;
        delete dummy;
        return cur;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);
        
        ListNode* ret = Solution().swapPairs(head);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}