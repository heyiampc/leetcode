class Solution {
public:
    int minSteps(string s, string t) {
//         unordered_map<char,int> mp1,mp2;
//         for(int i=0;i<s.size();i++)
//         {
//             mp1[s[i]]++;
//             mp2[t[i]]++;
//         }
//         int cnt=0;
//         for(auto &[a,b]:mp2)
//         {
//             int c=mp1[a];
//             if(mp1.find(a)!=mp1.end() && c>0 && b>0)
//             {
//                     int mini=min(mp1[a],mp2[a]);
//                     mp1[a]-=mini;
//                     mp2[a]-=mini;
                
//             }
//             cnt+=b;
//         }
//         return cnt;
        
        //Alt Solution
        int mp[26]={};
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]-'a']++;
            mp[t[i]-'a']--;
        }
        int cnt=0;
        for(int i=0;i<26;i++)
        {
            cnt+=abs(mp[i]);
        }
        return cnt/2;
        
        
    }
};