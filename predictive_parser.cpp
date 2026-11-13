#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<char> st;
    string input;
    int ip = 0;

    cout << "Enter input string (use i for identifier): ";
    cin >> input;

    input += '$';

    st.push('$');
    st.push('E');

    cout << "\nStack\t\tInput\t\tAction\n";

    while (!st.empty()) {

        char X = st.top();
        char a = input[ip];

        // Display stack
        stack<char> temp = st;
        string s = "";

        while (!temp.empty()) {
            s = temp.top() + s;
            temp.pop();
        }

        cout << s << "\t\t" << input.substr(ip) << "\t\t";

        if (X == '$' && a == '$') {
            cout << "Accept\n";
            return 0;
        }

        if (X == a) {
            st.pop();
            ip++;
            cout << "Match " << a << endl;
        }

        else if (X == 'E') {
            st.pop();

            if (a == 'i' || a == '(') {
                st.push('R');
                st.push('T');
                cout << "E -> TR\n";
            }
            else {
                cout << "Error\n";
                return 0;
            }
        }

        else if (X == 'R') {
            st.pop();

            if (a == '+') {
                st.push('R');
                st.push('T');
                st.push('+');
                cout << "R -> +TR\n";
            }
            else if (a == ')' || a == '$') {
                cout << "R -> epsilon\n";
            }
            else {
                cout << "Error\n";
                return 0;
            }
        }

        else if (X == 'T') {
            st.pop();

            if (a == 'i' || a == '(') {
                st.push('Y');
                st.push('F');
                cout << "T -> FY\n";
            }
            else {
                cout << "Error\n";
                return 0;
            }
        }

        else if (X == 'Y') {
            st.pop();

            if (a == '*') {
                st.push('Y');
                st.push('F');
                st.push('*');
                cout << "Y -> *FY\n";
            }
            else if (a == '+' || a == ')' || a == '$') {
                cout << "Y -> epsilon\n";
            }
            else {
                cout << "Error\n";
                return 0;
            }
        }

        else if (X == 'F') {
            st.pop();

            if (a == 'i') {
                st.push('i');
                cout << "F -> i\n";
            }
            else if (a == '(') {
                st.push(')');
                st.push('E');
                st.push('(');
                cout << "F -> (E)\n";
            }
            else {
                cout << "Error\n";
                return 0;
            }
        }

        else {
            cout << "Error\n";
            return 0;
        }
    }

    cout << "Rejected\n";
    return 0;
}
