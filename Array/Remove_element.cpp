#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
  
    int removeElement(vector<int>& nums, int val) {
        int k = 0;  // This will keep track of the next position to place a valid element

        for (int i = 0; i < nums.size(); i++) {
            // If the current element is not equal to the value we want to remove
            if (nums[i] != val) {
                nums[k] = nums[i];  // Move it to the front of the array
                k++;  // Move the write pointer ahead
            }
            // If nums[i] == val, we simply skip it 
        }

        // After the loop, 'k' is the new length of the array without 'val'
        return k;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;

    // Call the removeElement function
    int newLength = sol.removeElement(nums, val);

    // Output the new length of the array
    cout << "New length: " << newLength << endl;

    // Print the modified array 
    cout << "Modified array: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
