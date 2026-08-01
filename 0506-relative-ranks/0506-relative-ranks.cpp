class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        unordered_map<int, int> index;
        int n = score.size();
        vector<int> scorecopy(n);
        copy(score.begin(),score.end(),scorecopy.begin());
        
        vector<string> ans(n);
        for(int i=0;i<n;i++){
            index[scorecopy[i]] = i;
        }
        sort(scorecopy.begin(),scorecopy.end(),greater<int>());
        for(int i=0;i<n;i++){
            if(i==0){
                ans[index[scorecopy[i]]] = "Gold Medal";
            }else if(i == 1){
                ans[index[scorecopy[i]]] = "Silver Medal";
            }else if(i == 2){
                ans[index[scorecopy[i]]] = "Bronze Medal";
            }else{
                ans[index[scorecopy[i]]] = to_string(i+1);
            }
        }
        return ans;
    }
};