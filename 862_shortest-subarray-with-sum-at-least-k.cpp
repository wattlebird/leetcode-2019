#include "util.h"

using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        vector<int> agg(A.size() + 1, 0);
        for(int i = 0; i < A.size(); i++) {
            agg[i+1] = agg[i] + A[i];
        }
        deque<int> S;
        int len = agg.size();
        for(int i = 0; i < agg.size(); i++) {
            while (!S.empty() && agg[S.back()] > agg[i]) {
                S.pop_back();
            }
            S.push_back(i);
            while (!S.empty() && agg[S.back()] - agg[S.front()] >= K) {
                len = min(len, S.back() - S.front());
                S.pop_front();
            }
        }
        return len == agg.size() ? -1 : len;
    }

    int shortestSubarray2(vector<int> A, int K) {
        int N = A.size(), res = N + 1;
        deque<int> d;
        for (int i = 0; i < N; i++) {
            if (i > 0)
                A[i] += A[i - 1];
            if (A[i] >= K)
                res = min(res, i + 1);
            while (d.size() > 0 && A[i] - A[d.front()] >= K)
                res = min(res, i - d.front()), d.pop_front();
            while (d.size() > 0 && A[i] <= A[d.back()])
                d.pop_back();
            d.push_back(i);
        }
        return res <= N ? res : -1;
    }
};

int main() {
    vector<int> A = {1,2,3,4};
    int K = 4;
    Solution slu;
    cout << slu.shortestSubarray(A, K) << endl;
    A = {1};
    cout << slu.shortestSubarray(A, 1) << endl;
    A = {1, 2};
    cout << slu.shortestSubarray(A, 4) << endl;
    A = {2,-1,2};
    cout << slu.shortestSubarray(A, 3) << endl;
    A = {77,19,35,10,-14};
    cout << slu.shortestSubarray(A, 19) << endl;
    A = {56,-21,56,35,-9};
    cout << slu.shortestSubarray(A, 61) << endl;
    return 0;
}