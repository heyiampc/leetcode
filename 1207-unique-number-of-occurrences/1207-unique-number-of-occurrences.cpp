class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> map;
        set<int> s;
        vector<int> v;
        for(auto x: arr)
        {
            map[x]++;
        }
        for(auto it:map)
        {
            s.insert(it.second);
            v.push_back(it.second);
        }
        return v.size()==s.size();
    }
};