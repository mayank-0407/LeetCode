class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());

        vector<vector<int>> ans;
        for(int i = 0; i < arr.size(); i++){
            int start = arr[i][0], end = arr[i][1];
            if(ans.empty() || ans.back()[1] < start){
                ans.push_back(arr[i]);
            }else{
                ans.back()[1] = max(ans.back()[1], end);
            }
        } 
        return ans;
    }
};