#include <iostream>
#include <string>
#include <set>
#include <vector>

class Stack {
public:
    bool isEmpty() const;
    char top();
    int CheckSize();
    void push(char num);
    char pop();
    const int NO_VALUE = NULL;
private:
    std::vector<char> vec;
};

bool Stack::isEmpty() const {
    return vec.empty();
}

int Stack::CheckSize() {
    return vec.size();
}

void Stack::push(char num) {
    vec.push_back(num);
}

char Stack::pop() {
    if (!vec.empty()) {
        char last = vec[vec.size() - 1];
        vec.erase(vec.begin() + vec.size() - 1);
        return last;
    } else {
        return (char) NO_VALUE;

    }
}

char Stack::top() {
    return vec[vec.size() - 1];
}

std::string isBalanced(const std::string &s) {
    Stack stack;
    std::string flag;
    std::set<char> open = {'{', '[', '('};
    std::set<char> close = {'}', ']', ')'};
    int runner = 0;
    int start = 1;

    if (s.size() % 2 != 0) {
        flag = "NO";
    } else {
        stack.push(
                s[runner]);
        for (int ch = start; ch < s.size(); ch++) {
            if (stack.isEmpty()) {
                stack.push(s[start]);
            } else if (open.find(stack.top()) != open.end() &&
                       open.find(s[ch]) != open.end()) {
                stack.push(s[ch]);
            } else if (close.find(stack.top()) != close.end()) {
                flag = "NO";
            } else if (open.find(stack.top()) != open.end() &&
                       close.find(s[ch]) != close.end()) {
                if (stack.top() == '[' &&
                    s[ch] == ']') {
                    stack.push(s[ch]);
                    stack.pop();
                    stack.pop();
                } else if (stack.top() == '{' && s[ch] == '}') {
                    stack.push(s[ch]);
                    stack.pop();
                    stack.pop();
                } else if (stack.top() == '(' && s[ch] == ')') {
                    stack.push(s[ch]);
                    stack.pop();
                    stack.pop();
                } else {
                    flag = "NO";
                }
            }
            start++;
            runner++;
        }
        if (stack.isEmpty()) {
            flag = "YES";
        } else {
            flag = "NO";
        }
    }
    return flag;
}


int main() {
    std::string s;
    std::cin >> s;

    std::cout << isBalanced(s);

    return 0;
}