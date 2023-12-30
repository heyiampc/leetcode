class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n=words.size();
        unordered_map<char,int> mp;
        for(auto &x:words)
        {
            for(auto &x1:x)
            {
                mp[x1]++;
            }
        }
        for(auto &[a,b]:mp)
        {
            if(b%n!=0)
                return false;
        }
        return true;
    }
};