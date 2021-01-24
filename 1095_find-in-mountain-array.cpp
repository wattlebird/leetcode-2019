#include "util.h"

using namespace std;

class MountainArray {
public:
    MountainArray(vector<int>& arr):arr(arr) {};
    int get(int index) {
        return arr[index];
    }
    int length() {
        return arr.size();
    }
private:
    vector<int> arr;
};

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        // find the peak
        int l = mountainArr.length();
        int b = 0, e = l, p;
        while (e - b > 1) {
            int m = b + (e - b) / 2;
            int pm = m - 1;
            if (mountainArr.get(pm) < mountainArr.get(m)) b = m;
            else e = m;
        }
        // b is the peak;
        if (mountainArr.get(b) == target) return b;
        p = b, b = 0, e = p;
        while (e - b > 0) {
            int m = b + (e - b) / 2;
            int t = mountainArr.get(m);
            if (t == target) return m;
            else if (t < target) b = m + 1;
            else e = m;
        }
        b = p + 1, e = l;
        while (e - b > 0) {
            int m = b + (e - b) / 2;
            int t = mountainArr.get(m);
            if (t == target) return m;
            else if (t > target) b = m + 1;
            else e = m;
        }
        return -1;
    }
};

int main() {
    vector<int> data;
    Solution slu;
    data = {1,2,3,4,5,3,1};
    MountainArray mt(data);
    cout << slu.findInMountainArray(3, mt) << endl;
    data = {0,1,3,4,2,1};
    mt = MountainArray(data);
    cout << slu.findInMountainArray(2, mt) << endl;
    return 0;
}