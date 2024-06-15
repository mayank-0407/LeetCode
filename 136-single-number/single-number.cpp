class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int>  ans;
        for(int i=0;i<nums.size();i++)
            ans[nums[i]]++;
        for(auto &it:ans){
            if(it.second !=2){
                return it.first;
            }
        }
        return -1;
    }
};