class Solution {
public:
    int rob(vector<int>& nums) {
        int prev=nums[0],prev2=0;
        for(int i=1;i<nums.size();i++){
            int take=nums[i];
            if(i>1)take+=prev2;
            int nottake=prev;
            int curri=max(take,nottake);
            prev2=prev;
            prev=curri;
        }
        return prev;
    }
};