class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1 = -1000,max2=-1000,max3 = -1000,min1=0,min2=0;
        for(int num : nums){
            if(num>=max1){
                max3=max2;
                max2 = max1;
                max1 = num;
            }

            else if(num>=max2){
                max3 = max2;
                max2 = num;
            }
            else if(max3 <= num){
                max3 = num;
            }

            if(min1 >= num){
                min2 = min1;
                min1 = num;
            }
            else if(min2 >= num){
                min2 = num;
            }
        }
       
        int product = max(max1*max2*max3,min1*min2*max1);
        return product;
    }
};