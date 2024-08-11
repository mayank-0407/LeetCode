class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size(), maxi = INT_MIN;
        int count = 0;
        for(int i = 0; i<n; i++){
            if(nums[i]==0){
                maxi = max(maxi, count);
                count = 0;
            }
            else count++;
        }        
        maxi = max(maxi, count);
        return maxi;
    }
};