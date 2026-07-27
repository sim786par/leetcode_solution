class Solution {
public:
    bool consecutiveSetBits(int n) {
        string res = "";
        int count =0;
        while(n!=0){
            int rem = n%2;
            if(rem == 1) res+='1';
            else res+='0';
            n/=2;
        }
        for(int i=0;i<res.size();i++){
            if(res[i] == res[i+1] && res[i] == '1'){
                count++;
            }
        }
        return count==1?true: false;
    }
};