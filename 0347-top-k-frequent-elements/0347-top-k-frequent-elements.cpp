class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto &x:nums)
            mp[x]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>> pq;
        
        for(auto &x:mp)
        {
            pq.push({x.second,x.first});
        }
        vector<int> ans;
        while(k--)
        {
            int p=pq.top().second;
            pq.pop();
            ans.push_back(p);
        }
        return ans;
    }
};