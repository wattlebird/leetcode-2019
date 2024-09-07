#include "util.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int b = nums1.front() + nums2.front(), e = nums1.back() + nums2.back(), m, lb, ub;
        while(b < e) {
            m = (b + e) / 2;
            int cnt = countKPairs(nums1, nums2, m, lb, ub);
            if (cnt == k) break;
            else if (cnt > k) {
                e = lb;
            } else {
                b = ub;
            }
        }
        vector<vector<int>> rtn = listKPairs(nums1, nums2, ub, k);
        return rtn;
    }

    int countKPairs(vector<int>& nums1, vector<int>& nums2, int m, int& lb, int& rb) {
        lb = nums1.front() + nums2.front(), rb = nums1.back() + nums2.back();
        int i1 = 0, i2 = nums2.size() - 1, cnt = 0;
        
        while(i1 < nums1.size() && i2 >= 0) {
            int cur = nums1[i1] + nums2[i2];
            if (cur <= m) {
                lb = max(lb, cur);
                i1++;
                cnt += i2 + 1;
            } else {
                rb = min(rb, cur);
                i2--;
            }
        }
        return cnt;
    }

    vector<vector<int>> listKPairs(vector<int>& nums1, vector<int>& nums2, int m, int k) {
        vector<vector<int>> rtn;
        int i1 = 0, e = nums2.size() - 1;
        while (i1 < nums1.size()) {
            while (e >= 0 && nums1[i1] + nums2[e] > m) e--;
            for(int i2 = e; i2 >= 0; i2--) {
                rtn.push_back({nums1[i1], nums2[i2]});
            }
            if (e >= 0) i1++;
            else break;
        }
        sort(rtn.begin(), rtn.end(), [](const vector<int>& lhs, const vector<int>& rhs){ return lhs[0]+lhs[1] < rhs[0]+rhs[1]; });
        if (k < rtn.size()) return vector<vector<int>>(rtn.begin(), rtn.begin()+k);
        else return rtn;
    }
};


int main() {
    Solution slu;
    vector<int> nums1, nums2;
    nums1 = {1, 7, 11};
    nums2 = {2, 4, 6};
    auto rtn = slu.kSmallestPairs(nums1, nums2, 3);
    cout << vectorOfIntegerVectorToString(rtn) << endl;
    nums1 = {1,1,2};
    nums2 = {1,2,3};
    rtn = slu.kSmallestPairs(nums1, nums2, 2);
    cout << vectorOfIntegerVectorToString(rtn) << endl;
    nums1 = {1,2};
    nums2 = {3};
    rtn = slu.kSmallestPairs(nums1, nums2, 3);
    cout << vectorOfIntegerVectorToString(rtn) << endl;
    return 0;
}