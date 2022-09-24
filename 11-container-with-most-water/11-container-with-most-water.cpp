class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        if(n==1) return n;
        int x=0;
        int y=n-1;
        if(n==2) return min(height[x],height[y]);
        int area=0;
        while(x<y)
        {
            int l=min(height[x],height[y]);
            int b=y-x;
            int c_area=l*b;
            if(c_area>area) 
            {
                area=c_area;
            }
            if(l==height[x]) x++; else y--;
        }
        return area;
    }
};