class Solution {
public:
const int mod = (int)1e9 + 7;

    // Function to count the number of ways to achieve the target sum
    int findWays(vector<int> &num, int tar) {
        int n = num.size();

        vector<int> prev(tar + 1, 0);

        if (num[0] == 0)
            prev[0] = 2;  // 2 cases - pick and not pick
        else
            prev[0] = 1;  // 1 case - not pick

        if (num[0] != 0 && num[0] <= tar)
            prev[num[0]] = 1;  // 1 case - pick

        for (int ind = 1; ind < n; ind++) {
            vector<int> cur(tar + 1, 0);
            for (int target = 0; target <= tar; target++) {
                int notTaken = prev[target];

                int taken = 0;
                if (num[ind] <= target)
                    taken = prev[target - num[ind]];

                cur[target] = (notTaken + taken) % mod;
            }
            prev = cur;
        }
        return prev[tar];
    }


    int findTargetSumWays(vector<int>& arr, int target) {
        // ew boiled down the problem into nprev prob where we did s1-s2=target, They just changed
        // the language of the code to confuse you but we identified the pattern and used prev code to do so.
        int n=arr.size();
        int totSum = 0;
        for (int i = 0; i < n; i++) {
            totSum += arr[i];
        }

        // Checking for edge cases
        if (totSum - target < 0 || (totSum - target) % 2 != 0)
            return 0;  // Not possible to achieve the target sum

        return findWays(arr, (totSum - target) / 2);
    }
};