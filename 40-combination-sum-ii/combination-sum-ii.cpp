class Solution {
public:
    vector<vector<int>> ans;
    void solve(int idx, vector<int>& sub, vector<int>& arr, int target){
        if(target == 0){
            ans.push_back(sub);
            return;
        }
        for(int i = idx; i < arr.size(); i++){
            if(i > idx && arr[i-1] == arr[i]) continue;
            if(arr[i]>target) break;

            sub.push_back(arr[i]);
            solve(i+1, sub, arr, target - arr[i]);
            sub.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        solve(0, temp, candidates, target);
        return ans;
    }
};