class Solution {
public:
void solve(int idx,vector<int> &arr,int target,vector<vector<int>> &ans,vector<int> &ds){
    if(target==0){
        ans.push_back(ds);
        return;
    }
    for(int i=idx;i<arr.size();i++){
        if(i>idx && arr[i]==arr[i-1]) continue;
        if(arr[i]>target) break;
        ds.push_back(arr[i]);
        solve(i+1,arr,target-arr[i],ans,ds);
        ds.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(),candidates.end());
        solve(0,candidates,target,ans,ds);
        return ans;
    }
};