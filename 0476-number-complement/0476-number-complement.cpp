class Solution {
public:
    int findComplement(int num) {
        unsigned int mask = 1;
        
        // Expand the mask until it covers all significant bits of num
        while (mask < num) {
            mask = (mask << 1) | 1;
        }
        
        // XORing num with the mask flips all its bits
        return num ^ mask;
    }
};
