class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxHeap;
        for(int i = 0; i < nums.size(); i++){
            maxHeap.push(nums[i]);
        }
        int ans;
        while(!maxHeap.empty() && k > 0){
            ans = maxHeap.top();
            maxHeap.pop();
            k--;
        }
        return ans;
    }
};