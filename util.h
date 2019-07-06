#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void trimLeftTrailingSpaces(std::string &input) {
    input.erase(input.begin(), std::find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(std::string &input) {
    input.erase(std::find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

std::vector<int> stringToIntegerVector(std::string input) {
    std::vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    std::stringstream ss;
    ss.str(input);
    std::string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

std::vector<Interval> stringToIntervalVector(std::string input) {
    std::vector<Interval> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    size_t b = 0, e;
    std::string delim = "]", start = "[";
    b = input.find_first_of(start, b);
    while(b != std::string::npos) {
        e = input.find_first_of(delim, b);
        e++;
        std::vector<int> interval = stringToIntegerVector(input.substr(b, e - b));
        output.push_back(Interval(interval[0], interval[1]));
        b = input.find_first_of(start, e);
    }
    return output;
}

int stringToInteger(std::string input) {
    return stoi(input);
}

std::string integerVectorToString(std::vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    std::string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += std::to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

std::string intervalVectorToString(std::vector<Interval> list) {
    if (list.size() == 0) return "[]";
    std::string rst;
    for(size_t i=0; i!=list.size(); i++){
        rst += "[" + std::to_string(list[i].start) + ", " + std::to_string(list[i].end) + "], ";
    }
    return "[" + rst.substr(0, rst.length() - 2) + "]";
}

TreeNode* stringToTreeNode(std::string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    std::string item;
    std::stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    std::queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

std::string boolToString(bool input) {
    return input ? "True" : "False";
}

ListNode* stringToListNode(std::string input) {
    // Generate list from the input
    std::vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

std::string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    std::string result;
    while (node) {
        result += std::to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}