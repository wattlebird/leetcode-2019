#include "util.h"

using namespace std;

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) return head;
        ListNode *slow = head, *fast = head;
        while (fast != nullptr) {
            slow = slow -> next;
            fast = fast -> next;
            if (fast != nullptr) fast = fast -> next;
            if (fast != nullptr && slow == fast) break;
        }
        if (fast == nullptr) return nullptr;
        slow = head;
        while (fast != slow) {
            fast = fast -> next;
            slow = slow -> next;
        }
        return fast;
    }
};