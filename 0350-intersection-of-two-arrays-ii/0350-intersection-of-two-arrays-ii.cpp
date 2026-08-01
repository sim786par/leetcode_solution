class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        // sort(nums1.begin(),nums1.end());
        // sort(nums2.begin(),nums2.end());
        // int i=0,j=0;
        // while(i<nums1.size() && j<nums2.size()){
        //     if(nums1[i] < nums2[j]){
        //         i++;
        //     }else if(nums1[i] >nums2[j]){
        //         j++;
        //     }else{
        //         res.push_back(nums1[i]);
        //         i++;
        //         j++;
        //     }
        // }

        unordered_map<int,int> mp;
        for(int i=0;i<nums1.size();i++){
            mp[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++){
            if(mp[nums2[i]] >0){
                mp[nums2[i]]--;
                res.push_back(nums2[i]);
            }
        }
        return res;
    }
};