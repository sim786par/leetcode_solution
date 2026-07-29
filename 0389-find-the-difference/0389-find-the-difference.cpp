class Solution {
public:
    char findTheDifference(string s, string t) {
        //with string conversion technique
        // int sum = 0;
        // for(char c : t) sum +=c;
        // for(char c : s) sum -=c;
        // return (char) sum; 

        //with bitwise xor
        char res = 0;
        for(char c : t) res ^=c;
        for(char c : s) res ^= c;
        return res;
    }
};