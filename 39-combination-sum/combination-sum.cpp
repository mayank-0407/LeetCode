class Solution {
public:
    vector<vector<int>> ans;
    void find(int idx, vector<int>& thisarr, vector<int>& arr, int target){
        if(idx == arr.size()){
            if(target == 0)ans.push_back(thisarr);
            return;
        }
        if(arr[idx] <= target){
            thisarr.push_back(arr[idx]);
            find(idx, thisarr, arr, target - arr[idx]);
            thisarr.pop_back();
        } 
        find(idx + 1, thisarr, arr, target);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<int> temp;
        find(0, temp, arr,target);
        return ans;   
    }
};