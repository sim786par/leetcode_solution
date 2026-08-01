class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //O(nlog n)
        // sort(nums.begin(),nums.end());
        // for(int i=1;i<nums.size();i++){
        //     if(nums[i] == nums[i-1]){
        //         return true;
        //     }
        // }
        // return false;

        //hash set
        unordered_set<int> seen;
        for(int num : nums){
            if(seen.count(num)>0){
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};