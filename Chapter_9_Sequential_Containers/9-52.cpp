#include <stack>
#include <string>
#include <iostream>

std::string calculateStr(const std::string& s);

std::string evalParenthesesExpression(const std::string& expression) {
    std::stack<char> stk;
    for (const auto& c : expression) {
        if (c == ')') {
            std::string str;
            while (!stk.empty() && stk.top() != '(') {
                str += stk.top();
                stk.pop();
            }
            if (stk.empty()) {
                std::cerr << "Error: parentheses not match in expression: " << expression << std::endl;
                return "";
            }
            stk.pop();
            str = calculateStr(std::string(str.rbegin(), str.rend()));
            for (const auto& e : str)
                stk.push(e);
        } else {
            stk.push(c);
        }
    }
    std::string str;
    while (!stk.empty()) {
        if (stk.top() == '(') {
            std::cerr << "Error: parentheses not match in expression: " << expression << std::endl;
            return "";
        }
        str += stk.top();
        stk.pop();
    }
    str = calculateStr(std::string(str.rbegin(), str.rend()));
    return str;
}

std::string calculateStr(const std::string& s) {
    return s;
}

int main() {
    std::cout << evalParenthesesExpression("12+34-56-((78-9)+10") << std::endl;
    std::cout << evalParenthesesExpression("(12+34)-(56-((78-9)+10))") << std::endl;
    std::cout << evalParenthesesExpression("((12+34-(56-10)-1") << std::endl;
    std::cout << evalParenthesesExpression("12+34)-(56-10)-1") << std::endl;

    std::string expression;
    std::cin >> expression;
    std::cout << evalParenthesesExpression(expression) << std::endl;

    return 0;
}