class Solution {
public:
    int xorOperation(int n, int start) {
        int res = 0;
        vector<int> arr(n,0);
        for(int i=0;i<arr.size();i++){
            arr[i] = start+2*i;
            res ^= arr[i]; 
        }
        return res;
    }
};