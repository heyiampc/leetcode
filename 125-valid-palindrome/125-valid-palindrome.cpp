#define pb push_back
class Solution {
public:
    bool isValid(char s)
    {
        if((s>='a' && s<='z') || (s>='A' && s<='Z') || (s>='0' &&  s<='9')) return true;
        return false;
    }
    bool isPalindrome(string s) {
         vector<char> v{};
        for(int i=0;i<s.length();i++)
        {
            if(isValid(s[i])) v.pb(s[i]); 
        }
        if(v.empty()) return true;
        int j=v.size()-1;
    for(int i=0;i<v.size();i++)
    {
          v[i]= tolower(v[i]);
          v[j]= tolower(v[j]);
        if(v[i]!=v[j--])
        {
            return false;
        }
    }
        return true;
    }
};