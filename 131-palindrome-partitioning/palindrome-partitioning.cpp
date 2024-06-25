class Solution {
public:
    void solve(int idx,vector<vector<string>> &res,string s, vector<string> &thisstring){
        if(idx==s.length()){
            res.push_back(thisstring);
            return;
        }
        for(int i=idx;i<s.size();i++){
            if(isPlaindrome(s,idx,i)){
                thisstring.push_back(s.substr(idx,i-idx+1));
                solve(i+1,res,s,thisstring);
                thisstring.pop_back();
            }
        }
    }
    bool isPlaindrome(string s,int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--])
            return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> ans;
        solve(0,res,s,ans);
        return res;
    }
};