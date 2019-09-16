#include "util.h"

using namespace std;

class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head -> next == nullptr) return;
        ListNode *fast = head, *slow = head;
        
        while (fast) {
            slow = slow -> next;
            fast = fast -> next;
            if (fast) fast = fast -> next;
        }
        vector<ListNode*> stack;
        while(slow) {
            stack.push_back(slow);
            slow = slow -> next;
        }
        if (stack.size() <= 0) return;

        slow = head;
        for (int i = stack.size() - 1; i >= 0; i--) {
            fast = slow -> next;
            stack[i] -> next = fast;
            slow -> next = stack[i];
            slow = fast;
        }
        slow -> next = nullptr;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);
        
        Solution().reorderList(head);

        string out = listNodeToString(head);
        cout << out << endl;
    }
    return 0;
}