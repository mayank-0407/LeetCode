class Solution {
public:
    bool checkodd(int n){
        if(n%2==1) return true;
        return false;
    }
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count=0;
        for(int i=0;i<arr.size();i++){
            if(checkodd(arr[i])){
                count++;
            }else{
                count=0;
            }
            if(count==3) return true;
        }
        return false;
    }
};