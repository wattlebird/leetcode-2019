#include "util.h"

using namespace std;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 1) return lists[0];
        else if (lists.size() < 1) return nullptr;
        ListNode* rtn = lists[0];
        for (size_t i = 1; i != lists.size(); i++) {
            rtn = mergeTwoLists(rtn, lists[i]);
        }
        return rtn;
    }
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        ListNode* ptr = new ListNode(0);
        ListNode* rtn = ptr;
        while(l1 != nullptr || l2 != nullptr) {
            if (l1 == nullptr) {
                ptr -> next = l2;
                break;
            }
            if (l2 == nullptr) {
                ptr -> next = l1;
                break;
            }
            if (l1 -> val <= l2 -> val) {
                ptr -> next = l1;
                l1 = l1 -> next;
            } else {
                ptr -> next = l2;
                l2 = l2 -> next;
            }
            ptr = ptr -> next;
        }
        ptr = rtn -> next;
        delete rtn;
        return ptr;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        vector<ListNode*> list;
        for (size_t i=0; i!=n; i++) {
            getline(cin, line);
            list.push_back(stringToListNode(line));
        }
        
        ListNode* ret = Solution().mergeKLists(list);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}