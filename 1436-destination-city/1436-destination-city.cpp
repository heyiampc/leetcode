class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string,string> mp;
        for(auto &x:paths)
        {
            mp[x[0]]=x[1];
        }
        for(auto &x:paths)
        {
            if(mp.count(x[1])<1)
                return x[1];
        }
        return "A";
    }
};