#include "util.h"

using namespace std;

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0);
        dummy -> next = head;
        ListNode *cur = dummy;
        while (cur->next != nullptr) {
            ListNode *head = cur;
            ListNode *end = cur;
            for (int i=0; i!=k; i++) {
                end = end -> next;
                if (end == nullptr) break;
            }
            if (end == nullptr) break;
            
            ListNode *pre, *nxt;
            pre = head;
            cur = pre -> next;
            for (int i=0; i!=k; i++) {
                nxt = cur -> next;
                cur -> next = pre;
                pre = cur;
                cur = nxt;
            }
            head -> next -> next = cur;
            cur = head -> next;
            head -> next = pre;
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
        getline(cin, line);
        int k = stringToInteger(line);
        
        ListNode* ret = Solution().reverseKGroup(head, k);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}