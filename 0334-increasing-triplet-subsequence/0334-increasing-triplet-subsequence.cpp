class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int x=INT_MAX, y=INT_MAX;
        for(auto it:nums)
        {
            if(it<x) x=it;
            else if(it<y && it>x) y=it;
            else
            {
                if(y<it) return true;
            }
        }
        return false;
    }
};