class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        long long ans=0;
        long long peak=0;
        long long n=arr.size();
        for(int i=1;i<n;i++)
        {
            if(arr[i]>arr[i-1])
            {
                peak++;
                ans=max(ans,peak);
            }
            else
                peak=0;
        }
        // reverse(arr.begin(),arr.end());
        // for(int i=1;i<n;i++)
        // {
        //     if(arr[i]>arr[i-1])
        //     {
        //         peak++;
        //         ans=max(ans,peak);
        //     }
        //     else
        //         peak=0;
        // }
        return ans;
    }
};