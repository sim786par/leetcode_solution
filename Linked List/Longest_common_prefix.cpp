#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Solution class that contains the method to find the longest common prefix
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // If the input vector is empty, return an empty string
        if (strs.empty()) return "";

        // Assume the first string is the common prefix to start with
        string prefix = strs[0];

        // Compare the current prefix with each string in the list
        for (int i = 1; i < strs.size(); ++i) {
            // While the current string does NOT start with the prefix
            while (strs[i].find(prefix) != 0) {
                // Shorten the prefix by one character from the end
                prefix = prefix.substr(0, prefix.length() - 1);

                // If prefix becomes empty, then no common prefix exists
                if (prefix.empty()) return "";
            }
        }

        // Return the final common prefix after checking all strings
        return prefix;
    }
};

// Main function to test the solution
int main() {
    // Create a vector of strings to test
    //vector<string> strs = {"flower", "flow", "flight"};
    vector<string> strs1 = {"apple", "applepie", "applesauce"};
    vector<string> strs2 = {"dog", "racecar", "car"};

    // Create an instance of the Solution class
    Solution solution;

    // Call the longestCommonPrefix method and store the result
    string result1 = solution.longestCommonPrefix(strs1);
    string result2 = solution.longestCommonPrefix(strs2);

    // Print the result
    cout << "Longest Common Prefix: " << result1 << endl;
    cout << "Longest Common Prefix: " << result2 << endl;

    return 0;
}
