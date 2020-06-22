#include "util.h"

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        unsigned long r = num;
        while (r*r >= num) {
            if (r*r == num) return true;
            r = (unsigned long)(r - (r*r - num)/(2.0*r));
        }
        return false;
    }
};

int main() {
    Solution slu;
    cout << slu.isPerfectSquare(16) << endl;
    cout << slu.isPerfectSquare(14) << endl;
    cout << slu.isPerfectSquare(2000105819) << endl;
    return 0;
}