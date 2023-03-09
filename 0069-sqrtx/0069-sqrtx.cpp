class Solution {
public:
    int mySqrt(int x) {
        long long left=0;
        long long right=INT_MAX;
        long long ans;
        while(left<=right)
        {
            long long mid=left+(right-left)/2;
            if(mid*mid<=x)
            {
                ans=mid;
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }
        return ans;
    }
};