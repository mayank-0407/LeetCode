class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=INT_MIN;
        int thissum=0;
        for(int i=0;i<nums.size();i++){
            thissum+=nums[i];
            if(thissum>sum) sum=thissum;
            if(thissum<0) thissum=0;
        }
        return sum;
    }
};