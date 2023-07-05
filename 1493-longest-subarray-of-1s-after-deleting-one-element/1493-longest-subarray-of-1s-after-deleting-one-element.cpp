class Solution {
public:
    int countone(vector<int> &nums,int i)
    {
        int flag=0;
        int maxi=0;
        int l=0;
        int r=0;
        while(nums[l]!=1 && l<nums.size())
            l++;
        r=l+1;
        while(l<r && r<nums.size())
        {
            if(l==i && r!=i)
            {
                flag=true;
                // cout<<l<<" "<<r<<"|"<<nums[l]<<" "<<nums[r]<<endl;
                maxi=max(maxi,r-l);
                l++;
            }
            else if(l!=i && r==i)
            {
                flag=true;
                // cout<<l<<" "<<r<<"|"<<nums[l]<<" "<<nums[r]<<endl;
                maxi=max(maxi,r-l);
                r++; 
            }
            else{
            if(nums[l]==1 && nums[r]==1){
                // cout<<l<<" "<<r<<"|"<<nums[l]<<" "<<nums[r]<<endl;
                maxi=max(maxi,r-l);
                r++;
            }
            else if(nums[l]!=1){
                l++;
                if(l==r)
                    r++;
            }
            else if(nums[r]!=1)
            {
                l=r+1;
                r=l+1;
            }
        }
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