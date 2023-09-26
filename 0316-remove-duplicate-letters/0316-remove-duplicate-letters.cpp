class Solution {
public:
    string removeDuplicateLetters(string s) {
        string st="";
        int mp[26];
        int vis[26];
        memset(vis,0,sizeof(vis));
        memset(mp,0,sizeof(mp));
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]-'a']=i;
        }
        for(int i=0;i<s.size();i++)
        {
            int index=s[i]-'a';
            if(vis[index]==1)
                continue;
                while(st.size()>0 && st.back()> s[i] && mp[st.back()-'a']>i)
                {
                    vis[st.back()-'a']=0;
                    st.pop_back();
                }
                st.push_back(s[i]);
                vis[index]=1;
        }
        return st;
    }
};