#include "util.h"

using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* tail = dfs(head);
        tail->next = nullptr;
        return this->rtn;
    }
private:
    ListNode* rtn;
    ListNode* dfs(ListNode* cur) {
        if (cur->next == nullptr) {
            this->rtn = cur;
            return cur;
        } else {
            ListNode* nxt = dfs(cur->next);
            nxt->next = cur;
            return cur;
        }
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);
        
        ListNode* ret = Solution().reverseList(head);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}