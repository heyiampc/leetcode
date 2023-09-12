class Solution {
public:
    void print(vector<int> &vec)
    {
        for(auto &x:vec)
            cout<<x<<" ";
        cout<<endl;
    }
    int minop(vector<int> &nums)
    {
        map<int,int> mp;
        int ans=0;
        for(auto &it:nums)
        {
            if(mp.find(it)!=mp.end())
            {
                while(mp.find(it)!=mp.end() && mp[it]>0)
                {
                    it--;
                    ans++;
                }
            }
            if(it>0){
                mp[it]++;
            }
        }
        return ans;
    }
    int minDeletions(string s) {
        map<int,int> mp;
        for(auto &x:s)
            mp[x]++;
        vector<int> vec;
        for(auto &[a,b]:mp)
        {
            vec.push_back(b);
        }
        // sort(vec.begin(),vec.end());
        // print(vec);
        int ans=minop(vec);
        return ans;
    }
};