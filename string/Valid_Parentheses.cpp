#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;  // Stack to keep track of opening brackets

        // Map to store matching bracket pairs
        unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        // Loop through each character in the string
        for (char c : s) {
            // If it's a closing bracket
            if (pairs.count(c)) {
                // Check if the stack is empty or top doesn't match the pair
                if (st.empty() || st.top() != pairs[c]) {
                    return false;
                }
                st.pop();  // Valid pair, remove the opening bracket
            } else {
                st.push(c);  // Push opening bracket to the stack
            }
        }

        // If stack is empty, all brackets were matched correctly
        return st.empty();
    }
};

int main() {
    Solution sol;
    string input;

    cout << "Enter a string of brackets: ";
    cin >> input;

    // Check and print whether the string of brackets is valid
    if (sol.isValid(input)) {
        cout << "The string is valid." << endl;
    } else {
        cout << "The string is not valid." << endl;
    }

    return 0;
}
