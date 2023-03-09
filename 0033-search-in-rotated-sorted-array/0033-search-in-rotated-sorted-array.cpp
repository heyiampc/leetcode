class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i=0;
        for(auto x:nums)
        {
            if(x==target)
                return i;
            i++;
        }
        return -1;
    }
};