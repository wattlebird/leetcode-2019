#include "util.h"
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        lut.clear();
        diff = 500;
        vector<unsigned int> can = candidates(nums, k);
        if (can.empty()) return -1;
        this -> terminus = (1 << nums.size()) - 1;
        dfs(can, can);
        return diff == 500 ? -1 : diff;
    }
private:
    // n: current item, indicating current status;
    // arr: item to be added
    void dfs(vector<unsigned int> ns, vector<unsigned int>& arr) {
        set<unsigned int> nxt;
        for(unsigned int n: ns) {
            if (n == terminus) {
                diff = min(diff, lut[terminus]);
                return;
            }
            for(unsigned int x: arr) {
                if ((n & x) == 0) {
                    if (lut.count(n | x) > 0) lut[n|x] = min(lut[n|x], lut[n] + lut[x]);
                    else {
                        lut[n|x] = lut[n] + lut[x];
                        nxt.insert(n|x);
                    }
                }
            }
        }
        if (nxt.empty()) return;
        dfs(vector<unsigned int>(nxt.begin(), nxt.end()), arr);
    }

    vector<unsigned int> candidates(vector<int>& nums, int k) {
        vector<unsigned int> rtn;
        unsigned int len = nums.size() / k;
        unsigned int e = (1 << nums.size());
        for(unsigned int b = 0; b < e; b++) {
            unsigned int t = b, c = 0;
            while (t) { c += (1 & t); t >>= 1;}
            if (c == len) {
                set<int> temp = helper(nums, b);
                if (temp.size() == len) {
                    rtn.push_back(b);
                    lut[b] = *(temp.rbegin()) - *(temp.begin());
                }
            }
        }
        return rtn;
    }

    set<int> helper(vector<int>& nums, unsigned int mask) {
        int i = 0;
        set<int> rtn;
        while (mask) {
            if (mask & 1) rtn.insert(nums[i]);
            i++;
            mask >>= 1;
        }
        return rtn;
    }

    unordered_map<unsigned int, int> lut;
    int diff = 500;
    unsigned int terminus;
};

int main() {
    vector<int> num;
    Solution slu;
    num = {1};
    cout << slu.minimumIncompatibility(num, 1)<< endl;
    num = {1,2,1,4};
    cout << slu.minimumIncompatibility(num, 2)<< endl;
    num = {6,3,8,1,3,1,2,2};
    cout << slu.minimumIncompatibility(num, 4)<< endl;
    num = {5,3,3,6,3,3};
    cout << slu.minimumIncompatibility(num, 3)<< endl;
    num = {6,8,5,16,8,12,11,7,13,16,15,14,7,9,1,10};
    cout << slu.minimumIncompatibility(num, 4)<< endl;
    return 0;
}