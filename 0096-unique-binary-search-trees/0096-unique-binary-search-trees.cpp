class Solution {
public:
    map<int,int> mp;
    int fun(int n)
    {
        if(n<=1)
            return 1;
        if(n==2) return n;
        if(n==3) return 5;
        int ans=0;
        if(mp.count(n))
            return mp[n];
        for(int i=1;i<=n;i++)
            ans+=fun(i-1)*fun(n-i);
        return mp[n]=ans;
    }
    int numTrees(int n) {
        return fun(n);
    }
};