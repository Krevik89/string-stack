﻿#include <iostream>
#include <stack>

bool balanced(const std::string& s) {
    std::stack<char> stack;
    for (char c : s) {
        switch (c) {

        case '(': stack.push(')'); break;
        case '[': stack.push(']'); break;
        case '{': stack.push('}'); break;
        case '<': stack.push('>'); break;

        case ')':
        case ']':
        case '}':
        case '>':
            if (stack.empty() || stack.top() != c) {
                return false;
            }
            stack.pop();
            break;
        default:
            break;
        }
    }
    return stack.empty();
}

void test(const std::string& s) {
    std::cout << '"' << s << "\" " << (balanced(s) ? "yes" : "no") << '\n';
}

int main()
{
    test("");
    test("a(b[c]d)e");
    test("a(b[c)d]e");
    test("a(b[c]d");
    test("b[c]d)e");
}
