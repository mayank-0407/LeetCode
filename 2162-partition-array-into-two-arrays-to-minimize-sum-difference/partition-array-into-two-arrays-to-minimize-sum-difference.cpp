class Solution {
public:
    // int minimumDifference(vector<int>& arr) {
    //     int totSum = 0,n=arr.size();

    //     for (int i = 0; i < n; i++) {
    //         totSum += arr[i];
    //     }

    //     // Initialize a boolean vector 'prev' to represent the previous row of the DP table
    //     vector<bool> prev(totSum + 1, false);

    //     // Base case: If no elements are selected (sum is 0), it's a valid subset
    //     prev[0] = true;

    //     // Initialize the first row based on the first element of the array
    //     if (arr[0] <= totSum)
    //         prev[arr[0]] = true;

    //     // Fill in the DP table using a bottom-up approach
    //     for (int ind = 1; ind < n; ind++) {
    //         // Create a boolean vector 'cur' to represent the current row of the DP table
    //         vector<bool> cur(totSum + 1, false);
    //         cur[0] = true;

    //         for (int target = 1; target <= totSum; target++) {
    //             // Exclude the current element
    //             bool notTaken = prev[target];

    //             // Include the current element if it doesn't exceed the target
    //             bool taken = false;
    //             if (arr[ind] <= target)
    //                 taken = prev[target - arr[ind]];

    //             cur[target] = notTaken || taken;
    //         }

    //         // Set 'cur' as the 'prev' for the next iteration
    //         prev = cur;
    //     }

    //     int mini = 1e9;
    //     for (int i = 0; i <= totSum; i++) {
    //         if (prev[i] == true) {
    //             // Calculate the absolute difference between two subset sums
    //             int diff = abs(i - (totSum - i));
    //             mini = min(mini, diff);
    //         }
    //     }
    //     return mini;
    // }
    int minimumDifference(vector<int>& nums) {
        int n = nums.size()/2;
        vector<vector<int>> left(n+1), right(n+1); // left[i] stores all possible sums having i numbers taken into consideration, from the first half of nums (ie; index 0 to n-1, both included)
        for(int i=0;i<pow(2,n);i++){
            int ctr=0;
            int a=0,b=0;
            for(int j=0;j<n;j++){
                if(1<<j & i){
                    ctr++;
                    a+=nums[j];
                    b+=nums[n+j];
                }
            }
            left[ctr].push_back(a);
            right[ctr].push_back(b);
        }
        for(int i=0;i<=n;i++){
            sort(right[i].begin(), right[i].end());
        }
        int tot = left[n][0] + right[n][0]; // Take n elements from both halves, there is only one sum in both these arrays
        int ans = INT_MAX;
        for(int i=0;i<=n;i++){
            for(int l: left[i]){
                int ind = lower_bound(right[n-i].begin(), right[n-i].end(), (ceil(tot/2.0) - l)) - right[n-i].begin();
                if(ind<right[n-i].size()){
                    int a = l+right[n-i][ind];
                    ans = min(ans, 2*a-tot);
                }
            }
        }
        return ans;
    }
    
};
