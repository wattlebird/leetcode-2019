#include "util.h"
#include <climits>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int limit = 1 << nums.size();
        unordered_map<int, int> sum;
        for(int i = 1; i < limit; i++) {
            int cur = 0, index = i, btc = 0;
            while (index) {
                if (index & 0x1) btc++;
                index >>= 1;
            }
            if (btc*2 != nums.size()) continue;
            index = i;
            while (index > 0) {
                if (index & 0x1) sum[i]+=nums[cur];
                cur++;
                index >>= 1;
            }
        }
        int rtn = INT_MAX, mask = limit - 1;
        for(auto itr: sum) {
            int p = itr.first;
            int q = mask ^ p;
            rtn = min(rtn, abs(sum[q]- sum[p]));
        }
        return rtn;
    }
private:
    int setBitNumber(int n)
    {
        // Below steps set bits after
        // MSB (including MSB)
    
        // Suppose n is 273 (binary
        // is 100010001). It does following
        // 100010001 | 010001000 = 110011001
        n |= n >> 1;
    
        // This makes sure 4 bits
        // (From MSB and including MSB)
        // are set. It does following
        // 110011001 | 001100110 = 111111111
        n |= n >> 2;
        n |= n >> 4;
        n |= n >> 8;
        n |= n >> 16;
    
        // The naive approach would increment n by 1,
        // so only the MSB+1 bit will be set,
        // So now n theoretically becomes 1000000000.
        // All the would remain is a single bit right shift:
        //    n = n + 1;
        //    return (n >> 1);
        //
        // ... however, this could overflow the type.
        // To avoid overflow, we must retain the value
        // of the bit that could overflow:
        //     n & (1 << ((sizeof(n) * CHAR_BIT)-1))
        // and OR its value with the naive approach:
        //     ((n + 1) >> 1)
        n = ((n + 1) >> 1) |
            (n & (1 << ((sizeof(n) * CHAR_BIT)-1)));
        return n;
    }
};

int main() {
    Solution slu;
    vector<int> nums;
    nums = {76,8,45,20,74,84,28,1};
    cout << slu.minimumDifference(nums) << endl;
    nums = {7772197,4460211,-7641449,-8856364,546755,-3673029,527497,-9392076,3130315,-5309187,-4781283,5919119,3093450,1132720,6380128,-3954678,-1651499,-7944388,-3056827,1610628,7711173,6595873,302974,7656726,-2572679,0,2121026,-5743797,-8897395,-9699694};
    cout << slu.minimumDifference(nums) << endl;
    return 0;
}
