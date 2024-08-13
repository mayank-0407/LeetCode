class Solution {
public:
    vector<vector<string>> ans;

    bool isPalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start] != s[end]){
                return 0;
            }
            start++;
            end--;
        }
        return 1;
    }

    void solve(int idx, vector<string> path, string s){
        if(idx == s.size()){
            ans.push_back(path);
            return;
        }
        for(int i=idx; i<s.size(); i++){
            if(isPalindrome(s, idx, i)){
                path.push_back(s.substr(idx, i - idx + 1));
                solve(i+1, path, s);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        solve(0, temp, s);
        return ans;
    }
};