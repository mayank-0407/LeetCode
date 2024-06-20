class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size=nums.size(),l=0,h=size-1,mid;
        while(l<=h)
        {
            mid=(l+h)/2;
            if(nums.at(mid)==target)
                return mid;
            
            if(nums.at(l)<=nums.at(mid))
            {
                if(target>=nums.at(l)&&target<=nums.at(mid))
                h=mid-1;
                else
                l=mid+1;
            }
            else
                if(target>=nums.at(mid)&&target<=nums.at(h))
                    l=mid+1;
                else
                    h=mid-1;
        }
        return -1;
    }
};