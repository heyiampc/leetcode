class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int n) {
        if((nums.size()==1 && n==1 && nums[0]==0) || (nums.size()==2 && n==1 && (nums[0]==0 && nums[1]==0) ) )
            return true;
        if(nums.size()>2)
        {
            if(nums[0]==0 && nums[1]==0)
            {
                nums[0]=1;
                n--;
            }
            if(nums[nums.size()-1]==0 && nums[nums.size()-2]==0)
            {
                nums[nums.size()-1]=1;
                n--;
            }
        }
        for(int i=1;i<nums.size()-1;i++)
        {
            if(nums[i-1]==0 && nums[i+1]==0 && nums[i]==0)
            {
                cout<<i<<" ";
                nums[i]=1;
                n--;
            }
        }
        return n<=0;
    }
};