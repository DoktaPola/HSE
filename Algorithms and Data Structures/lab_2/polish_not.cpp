#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <map>

class Stack {
public:
    bool isEmpty() const;

    char top();

    int CheckSize();

    void push(char num);

    char pop();

//    const char NO_VALUE = NULL;
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
    }
    else {
        return '0';
    }
//        return (char) NO_VALUE;
//
//    }
}

char Stack::top() {
    return vec[vec.size() - 1];
}

class Stack_int {
public:
    bool isEmpty() const;

    int top();

    int CheckSize();

    void push(int num);

    int pop();

    const int NO_VALUE = NULL;
private:
    std::vector<int> vec;
};

bool Stack_int::isEmpty() const {
    return vec.empty();
}

int Stack_int::CheckSize() {
    return vec.size();
}

void Stack_int::push(int num) {
    vec.push_back(num);
}

int Stack_int::pop() {
    if (!vec.empty()) {
        int last = vec[vec.size() - 1];
        vec.erase(vec.begin() + vec.size() - 1);
        return last;
    } else {
        return NO_VALUE;

    }
}

int Stack_int::top() {
    return vec[vec.size() - 1];
}


int main() {
    std::string output;
//    std::string arithmetic_expr = "1+2*(3+4/2-(1+2))*2+1";
//    std::string arithmetic_expr = "1*2*3";
    std::string arithmetic_expr;
    std::cin >> arithmetic_expr;
    std::cout << "Expression:" << std::endl;
    std::cout << arithmetic_expr << std::endl;
    std::vector<char> nums_vec = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    std::map<char, int> expr_map = {{'+', 1},
                                    {'-', 1},
                                    {'*', 2},
                                    {'/', 2}};

    std::string s = "";
    std::vector<int> for_n;
    std::vector<char> for_expr;

    Stack opr;
    Stack_int nums;
    std::cout << "Reverse Polish Notation:" << std::endl;
    for (int i = 0; i < arithmetic_expr.size(); i++) {
        int res = -1;
        bool needed = std::find(nums_vec.begin(), nums_vec.end(), arithmetic_expr[i]) != nums_vec.end();
        while (needed) {
            res = arithmetic_expr[i] - '0';
            s += std::to_string(res);
            res = atoi(s.c_str());

            needed = std::find(nums_vec.begin(), nums_vec.end(), arithmetic_expr[i+1]) != nums_vec.end();
            i++;
        }
        if (res != -1){
            nums.push(res);
            output += std::to_string(res) + " ";
        }

        if (arithmetic_expr[i] == '+' || arithmetic_expr[i] == '-') {  // для закрыв нет
            if (opr.isEmpty()) {          // стек пуст, просто кладем
                opr.push(arithmetic_expr[i]);
            } else {
                if (1 < expr_map[opr.top()]) {   // сравниваю приоритет плюса с тем, что в стеке
                    int res = nums.pop();
                    char mult_or_div = opr.pop();
                    if (mult_or_div == '*') {
                        int num2 = nums.pop();
//                        output += std::to_string(num2) + " ";
//                        output += std::to_string(res) + " ";
                        res = num2 * res;
                        output += mult_or_div;
                        output += " ";
                    } else if (mult_or_div == '/') {
                        int num2 = nums.pop();
//                        output += std::to_string(num2) + " ";
//                        output += std::to_string(res) + " ";
                        res = num2 / res;  // целочисленно?????????
                        output += mult_or_div;
                        output += " ";
                    }
                    nums.push(res);
                } else if (1 == expr_map[opr.top()]) {  // если приоритеты равны
                    int res = nums.pop();
                    char pls_or_minus = opr.pop();
                    if (pls_or_minus == '+') {   // забираю + , лежащий в стеке
                        int num2 = nums.pop();
//                        output += std::to_string(num2) + " ";
//                        output += std::to_string(res) + " ";
                        res = num2 + res;
                        output += pls_or_minus;
                        output += " ";
                    } else if (pls_or_minus == '-') {
                        int num2 = nums.pop();
//                        output += std::to_string(num2) + " ";
//                        output += std::to_string(res) + " ";
                        res = num2 - res;
                        output += pls_or_minus;
                        output += " ";
                    }
                    nums.push(res);
                    opr.push(arithmetic_expr[i]);  // просто кладу
                } else if (opr.top() == '(') {  // ????
                    opr.push(arithmetic_expr[i]);
                }
            }
        } else if (arithmetic_expr[i] == '*' || arithmetic_expr[i] == '/') { ////////////////////////
            if (opr.isEmpty()) {          // стек пуст, просто кладем
                opr.push(arithmetic_expr[i]);
            } else {
                if (2 > expr_map[opr.top()]) {   // сравниваю приоритет плюса с тем, что в стеке, если меньше, просто кладу
                    if ((opr.top() == '+') || (opr.top() == '-')) {
                        opr.push(arithmetic_expr[i]);
                    }
                } else if (2 == expr_map[opr.top()]) {  // если приоритеты равны
                    int res = nums.pop();
                    char mult_or_div = opr.pop();
                    if (mult_or_div == '*') {
                        int num2 = nums.pop();
//                        output += std::to_string(num2) + " ";
//                        output += std::to_string(res) + " ";
                        res = num2 * res;
                        output += mult_or_div;
                        output += " ";
                    } else if (mult_or_div == '/') {
                        int num2 = nums.pop();
//                        output += std::to_string(num2) + " ";
//                        output += std::to_string(res) + " ";
                        res = num2 / res;  // целочисленно?????????
                        output += mult_or_div;
                        output += " ";
                    }
                    nums.push(res);
                    opr.push(arithmetic_expr[i]);  // кладу в стек */ без проверок   ?????
                } else if (opr.top() == '(') {
                    opr.push(arithmetic_expr[i]);   // ????
                }
            }
        } else if (arithmetic_expr[i] == '(') {
            opr.push(arithmetic_expr[i]);
        } else if (arithmetic_expr[i] == ')') {   // если закрывающаяся , то тут тоже прописать вывод...
            while (opr.top() != '('){  ///////////////////////
                char expr = opr.pop();
                int res = nums.pop();
                if (expr == '+') {
                    int num2 = nums.pop();
//                    output += std::to_string(num2) + " ";
//                    output += std::to_string(res) + " ";
                    res = num2 + res;
                    output += expr;
                    output += " ";
                } else if (expr == '-') {
                    int num2 = nums.pop();
//                    output += std::to_string(num2) + " ";
//                    output += std::to_string(res) + " ";
                    res = num2 - res;
                    output += expr;
                    output += " ";
                } else if (expr == '*') {
                    int num2 = nums.pop();
//                    output += std::to_string(num2) + " ";
//                    output += std::to_string(res) + " ";
                    res = num2 * res;
                    output += expr;
                    output += " ";
                } else if (expr == '/') {
                    int num2 = nums.pop();
//                    output += std::to_string(num2) + " ";
//                    output += std::to_string(res) + " ";
                    res = num2 / res;  // целочисленно?????????
                    output += expr;
                    output += " ";
                }
                nums.push(res);
//                i++;
            }
            opr.pop();  // убираю ( скобку
        }
        s = "";
    }
    while (!opr.isEmpty()) {
        char expr = opr.pop();
        int res = nums.pop();
        output += expr;
        output += " ";
        if (expr == '+') {
            res = nums.pop() + res;
        } else if (expr == '-') {
            res = nums.pop() - res;
        } else if (expr == '*') {
            res = nums.pop() * res;
        } else if (expr == '/') {
            res = nums.pop() / res;   // целочисленно?????????
        }
        nums.push(res);
    }
//    std::cout << "Reverse Polish Notation:" << std::endl;
    std::cout << output << std::endl;
    std::cout << "Result:" << std::endl;
    std::cout << nums.pop();
    return 0;
}

