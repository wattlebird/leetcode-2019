#include "util.h"

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findkthlargest(nums.begin(), nums.end(), k);
    }
private:
    int findkthlargest(vector<int>::iterator b, vector<int>::iterator e, int k) {
        vector<int>::iterator p = b, c = b;
        int m = *b;
        while (++p != e) {
            if (m < *p) {
                ++c;
                swap(*c, *p);
            }
        }
        swap(*c, *b);
        if (c - b == k - 1) return *c;
        else if (c - b < k - 1) return findkthlargest(c+1, e, k - 1 - (c - b));
        else return findkthlargest(b, c, k);
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        int ret = Solution().findKthLargest(nums, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}