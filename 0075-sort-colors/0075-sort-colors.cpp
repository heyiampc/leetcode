class Solution {
public:
    void print(int arr[])
    {
        for(int i=0;i<3;i++)
            cout<<arr[i];
    }
    void sortColors(vector<int>& nums) {
        int arr[3]={0};
        for(auto &x:nums)
            arr[x]++;
        int r=arr[0];
        int w=arr[1];
        int b=arr[2];
        for(int i;i<nums.size();i++)
        {
            if(r)
            {
            nums[i]=0;
            r--;
            cout<<" "<<r<<" ";
            }
            else if(w)
            {
            nums[i]=1;
            w--;
            cout<<" "<<w<<" ";
            }
            else if(b)
            {
            nums[i]=2;
            cout<<" "<<b<<" ";
            }
        }
    }
};