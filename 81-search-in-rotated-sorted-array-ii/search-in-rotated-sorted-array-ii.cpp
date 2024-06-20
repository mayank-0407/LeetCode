class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int size=nums.size(),l=0,h=size-1,mid;
        while(l<=h)
        {
            // to avoid duplicates
        while (l < h && nums[l] == nums[l + 1])
            ++l;
        while (l < h && nums[h] == nums[h - 1])
            --h;
            mid=(l+h)/2;
            if(nums.at(mid)==target)
                return true;
            
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
        return false;
    }
};