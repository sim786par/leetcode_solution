#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindromes
        if (x < 0) return false;

        long long rev = 0;  // Variable to store the reversed number
        int num = x;        // Store original number for comparison

        // Reverse the number digit by digit
        while (x != 0) {
            int digit = x % 10;         // Get the last digit
            rev = rev * 10 + digit;     // Add digit to reversed number
            x = x / 10;                 // Remove last digit from x
        }

        // Check if reversed number equals original
        return num == rev;
    }
};

int main() {
    Solution sol;
    int number;

    cout << "Enter a number: ";
    cin >> number;

    if (sol.isPalindrome(number)) {
        cout << number << " is a palindrome." << endl;
    } else {
        cout << number << " is not a palindrome." << endl;
    }

    return 0;
}
