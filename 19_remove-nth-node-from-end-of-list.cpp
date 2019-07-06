#include <string>
#include "util.h"

using namespace std;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n <= 0) return head;
        this->depth = n;
        ListNode* pre = new ListNode(0);
        pre->next = head;
        dfs(pre);
        ListNode* rtn = pre->next;
        delete pre;
        return rtn;
    }
private:
    int depth;
    int dfs(ListNode* head) {
        if (head == nullptr) return 0;
        else {
            int d = dfs(head -> next);
            if (d == depth) {
                head -> next = head -> next -> next;
            }
            return d + 1;
        }
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);
        getline(cin, line);
        int n = stringToInteger(line);
        
        ListNode* ret = Solution().removeNthFromEnd(head, n);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}