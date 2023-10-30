#define pi pair<int,int>
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        for(auto &it:arr)
        {
            int bit=__builtin_popcount(it);
            pq.push({bit,it});
        }
        vector<int> ans;
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            ans.push_back(it.second);
        }
        return ans;
    }
};