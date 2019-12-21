#include "util.h"

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return eliminateTopK(nums1, nums2, (nums1.size() + nums2.size() - 1) / 2, (nums1.size() + nums2.size()) & 0x1);
    }
private:
    double eliminateTopK(vector<int>& a1, vector<int>& a2, int k, bool isodd) {
        if (a1.size() == 0) return isodd ? a2[k] : (a2[k] + a2[k+1] + 0.0) / 2;
        if (a2.size() == 0) return isodd ? a1[k] : (a1[k] + a1[k+1] + 0.0) / 2;
        if (k == 0) {
            if (isodd) return a1[0] < a2[0] ? a1[0] : a2[0];
            else {
                int i = 0, j = 0, step = 2;
                double sum = 0.0;
                while (step > 0) {
                    if (i == a1.size()) sum += a2[j++];
                    else if (j == a2.size()) sum += a1[i++];
                    else {
                        sum += a1[i] < a2[j] ? a1[i++] : a2[j++];
                    }
                    step--;
                }
                return sum / 2;
            }
        }
        if (a1.back() <= a2.front()) {
            if (a1.size() <= k) {
                int i = k - a1.size();
                return isodd ? a2[i] : (a2[i] + a2[i+1] + 0.0) / 2;
            } else {
                vector<int> b1 = vector<int>(a1.begin() + k, a1.end());
                return eliminateTopK(b1, a2, 0, isodd);
            }
        } else if (a1.front() >= a2.back()) {
            if (a2.size() <= k) {
                int i = k - a2.size();
                return isodd ? a1[i] : (a1[i] + a1[i+1] + 0.0) / 2;
            } else {
                vector<int> b2 = vector<int>(a2.begin() + k, a2.end());
                return eliminateTopK(a1, b2, 0, isodd);
            }
        }

        if (a1.size() > a2.size()) swap(a1, a2);
        int b = 0, e = a1.size(), i = (b + e) / 2, j = k - i;
        do {
            if ((i==0 || a1[i-1] <= a2[j]) && (j==0 || a2[j-1] <= a1[i])) break;
            if (i != 0 && a1[i-1] > a2[j]) e = i;
            else if (j != 0 && a2[j-1] > a1[i]) b = i + 1;
            i = (b+e)/2;
            j = k-i;
        } while (b != e);
        vector<int> b1 = vector<int>(a1.begin() + i, a1.end());
        vector<int> b2 = vector<int>(a2.begin() + j, a2.end());
        return eliminateTopK(b1, b2, k - i - j, isodd);
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums1 = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> nums2 = stringToIntegerVector(line);
        
        double ret = Solution().findMedianSortedArrays(nums1, nums2);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}