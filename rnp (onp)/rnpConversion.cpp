#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

string ConvertToRPN(const string& input);
int Priority(char op);

int main()
{
    string onpTest = ConvertToRPN("3 + 4 * 2 / (1 - 5) ^ 2");
    cout << onpTest << endl;
    return 0;
}

int Priority(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

string ConvertToRPN(const string& input) {
    queue<string> outputQueue;
    stack<char> operatorStack;

    for (size_t i = 0; i < input.length(); i++) {
        if (input[i] == ' ')
            continue;

        if (isdigit(input[i])) {
            string number;
            while (i < input.length() && (isdigit(input[i]) || input[i] == '.')) {
                number += input[i];
                i++;
            }
            outputQueue.push(number);
            i--;
        }
        else if (input[i] == '(') {
            operatorStack.push('(');
        }
        else if (input[i] == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                string s(1, operatorStack.top());
                outputQueue.push(s);
                operatorStack.pop();
            }
            if (!operatorStack.empty() && operatorStack.top() == '(')
                operatorStack.pop();
        }
        else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '^') {
            while (!operatorStack.empty() && (
                (input[i] != '^' && Priority(operatorStack.top()) >= Priority(input[i])) ||
                (input[i] == '^' && Priority(operatorStack.top()) > Priority(input[i]))
            )) {
                string s(1, operatorStack.top());
                outputQueue.push(s);
                operatorStack.pop();
            }
            operatorStack.push(input[i]);
        }
    }

    while (!operatorStack.empty()) {
        string s(1, operatorStack.top());
        outputQueue.push(s);
        operatorStack.pop();
    }

    string result;
    while (!outputQueue.empty()) {
        result += outputQueue.front();
        outputQueue.pop();
        if (!outputQueue.empty())
            result += ' ';
    }

    return result;
}
