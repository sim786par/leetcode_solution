#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

vector<int> twoSum(vector<int>& nums, int target) {

    for (int i = 0; i < nums.size(); i++) {
            // Check the rest of the elements after the current one
            for (int j = i + 1; j < nums.size(); j++) {
                // If the sum of the two numbers equals the target
                if (nums[i] + nums[j] == target) {
                    // Return their indices as a vector
                    return {i, j};
                }
            }
        }
        // If no such pair is found, return an empty vector
        return {};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    // Call the twoSum function and store the result
    vector<int> result = sol.twoSum(nums, target);

    // Check if a valid result was found
    if (!result.empty()) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
        // Output should be: Indices: 0, 1 because 2 + 7 = 9
    } else {
        cout << "No two numbers add up to the target." << endl;
    }

    return 0;
}
