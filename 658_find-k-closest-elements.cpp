#include "util.h"

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if (arr[0] >= x) return vector<int>(arr.begin(), arr.begin() + k);
        int b = 0, e = arr.size(), m;
        while (e-b > 1) {
            m = b + (e - b) / 2;
            if (arr[m] >= x) e = m;
            else b = m;
        }
        if (b + 1 == arr.size()) return vector<int>(arr.end() - k, arr.end());
        if (abs(x - arr[b]) > abs(x - arr[e])) {b++; e++;}
        while (--k) {
            if (e == arr.size()) b--;
            else if (b == 0) e++;
            else {
                if (abs(x-arr[b-1]) > abs(x-arr[e])) e++;
                else b--;
            }
        }
        return vector<int>(arr.begin() + b, arr.begin() + e);
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> arr = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);
        getline(cin, line);
        int x = stringToInteger(line);
        
        vector<int> ret = Solution().findClosestElements(arr, k, x);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}