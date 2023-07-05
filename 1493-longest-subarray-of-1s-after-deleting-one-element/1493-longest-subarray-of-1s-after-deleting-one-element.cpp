class Solution {
public:
    int countone(vector<int> &nums,int i)
    {
        int flag=0;
        int maxi=0;
        int count=0;
        int l=0;
        while(nums[l]!=1 && l<nums.size())
            l++;
        if(l>i)
            flag=1;
        for(int j=l;j<nums.size();j++)
        {
            if(j==i){
                flag=1;
            }
            else if(nums[j]==1)
                count++;
            else{
                count=0;
            }
            maxi=max(maxi,count);
        }
        if(!flag) maxi++;
        return maxi;
    }
    int longestSubarray(vector<int>& nums) {
        int maxi=0;
        int flag=0; // for 0
        int flag1=0; //for 1
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1)
                flag1=1;
            if(nums[i]==0){
                flag=1;
                maxi=max(maxi,countone(nums,i));
            }
        }
        if(!flag)
            return nums.size()-1;
        if(!flag1)
            return 0;
        return maxi;
    }
};