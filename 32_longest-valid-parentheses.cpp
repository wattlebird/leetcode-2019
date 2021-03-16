#include "util.h"

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> stack = { -1 };
        int rtn = 0;
        for(int i = 0; i < s.length(); i++) {
            if (stack.back() != -1 && s[stack.back()] == '(' && s[i] == ')') {
                stack.pop_back();
                if (rtn < i - stack.back()) rtn = i - stack.back();
            } else {
                stack.push_back(i);
            }
        }
        return rtn;
    }
};

int main() {
    Solution slu;
    cout << slu.longestValidParentheses("(()") <<endl;
    cout << slu.longestValidParentheses(")()())") <<endl;
    cout << slu.longestValidParentheses("") <<endl;
}