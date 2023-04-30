class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,int> mp;
        for(auto &x:edges)
            for(auto &j:x)
                mp[j]++;
        int maxi=0;
        for(auto &x:mp){
            if(maxi<x.second){
                maxi=x.first;
            }
        }
        return maxi;
    }
};