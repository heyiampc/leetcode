class Solution {
public:
    int findPeakElement(vector<int>& arr) {
         int left=0;
        int right=arr.size()-1;
        int ans;
        while(left<right)
        {
            int mid=left+(right-left)/2;
            if(arr[mid]>arr[mid+1])
            {
                right=mid;
            }
            else
            {
                ans=mid+1;
                left=mid+1;
            }
        }
        return left;
    }
};