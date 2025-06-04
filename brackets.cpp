#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

bool Balance(const string &s) {
    stack<char> brackets;
    unordered_map<char, char> map_brackets = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            brackets.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (brackets.empty() || brackets.top() != map_brackets[c]) {
                return false;
            }
            brackets.pop();
        }
    }

    return brackets.empty();
}

int main() {
    string input;

    cout << "Сheck bracket sequence." << endl;
    cout << "Supported brackets: (), [], {}" << endl;
    cout << "To exit, enter '0'" << endl;

    while (true) {
        cout << "> Enter here: ";
        getline(cin, input);

        if (input == "0") {
            break;
        }

        if (Balance(input)) {
            cout << "✅ Right!" << endl;
        } else {
            cout << "❌ Incorrect!" << endl;
        }
    }

    cout << "Program ended." << endl;
    return 0;
}
