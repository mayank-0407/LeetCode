class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c==0 || c==1) return true;
        for(int a=1;a<=sqrt(c);a++){
            int val=c-pow(a,2);
            int b=sqrt(val);
            if(b*b==val){
                return true;
            }
        }
        return false;
    }
};