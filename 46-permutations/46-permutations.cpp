#define pb push_back
#define pbb pop_back
class Solution {
public:
    //Approach 1
    void helperfun(vector<vector<int>> &ans,vector<int> &ds,vector<int> arr, int freq[])
    {
        if(ds.size()==arr.size())
        {
            ans.pb(ds);
        }
        for(int i=0;i<arr.size();i++)
        {
            if(!freq[i])
            {
            ds.pb(arr[i]);
            freq[i]=1;
            helperfun(ans,ds,arr,freq);
            freq[i]=0;
            ds.pbb();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int freq[nums.size()];
        for(int i=0;i<nums.size();i++) freq[i]=0;
        helperfun(ans,ds,nums,freq);
        return ans;
    }
};