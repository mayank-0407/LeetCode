class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int n=s.size(),b1=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') {
                if(b1>0) ans+=s[i];
                b1++;
            }
            else {
                b1--;
                if(b1>0) ans+=s[i];
            }
        }
        return ans;
    }
};