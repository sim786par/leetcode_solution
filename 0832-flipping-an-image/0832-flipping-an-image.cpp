class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image[0].size();
        for(int i=0;i<image.size();i++){
            int left =0, right = n-1;
            while(left <= right){
                if(left == right){
                    image[i][left] ^= 1;
                }
                else{
                    //swap
                    int temp = image[i][left];
                    image[i][left] = image[i][right];
                    image[i][right] = temp;
                    //direct toggle
                    image[i][left] ^= 1;
                    image[i][right] ^= 1;
                }
                
                left++,right--;
            }       
        }
        return image;
    }
};