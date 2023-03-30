class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int l=0;
        int r=0;
        int n=s.size();
        int ans=0;
        while(r<n)
        {
            if(mp.find(s[r])!=mp.end())
                l=max(mp[s[r]]+1,l);
            mp[s[r]]=r;
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};