class Solution {
public:
    void print(unordered_map<char,int> &mp1,unordered_map<char,int> &mp2)
    {
        for(auto &[a,b]:mp1)
            cout<<a<<" "<<b<<endl;
        cout<<endl;
        for(auto &[a,b]:mp2)
            cout<<a<<" "<<b<<endl;
        cout<<endl;
    }
    
    int minSteps(string s, string t) {
        unordered_map<char,int> mp1,mp2;
        for(int i=0;i<s.size();i++)
        {
            mp1[s[i]]++;
            mp2[t[i]]++;
        }
        // print(mp1,mp2);
        int cnt=0;
        for(auto &[a,b]:mp2)
        {
            int c=mp1[a];
            if(mp1.find(a)!=mp1.end() && c>0 && b>0)
            {
                if(c==b)
                {
                    mp1[a]=0;
                    mp2[a]=0;
                }
                else
                {
                    int mini=min(mp1[a],mp2[a]);
                    mp1[a]-=mini;
                    mp2[a]-=mini;
                }
            }
        }
        // print(mp1,mp2);
        for(auto &[a,b]:mp2)
        {
            if(b)
            {
                cnt+=b;
            }
        }
        return cnt;
    }
};