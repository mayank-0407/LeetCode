class Solution {
public:
    int findDuplicate(vector<int>& arr) {
       unordered_map<int,int> mp;
       int n = arr.size();
       for(int i =0;i<n;i++){
           mp[arr[i]]++;
       }

       for(auto i : mp){
           if(i.second>1){
               return i.first;
           }
       }
       return -1;
    }
};