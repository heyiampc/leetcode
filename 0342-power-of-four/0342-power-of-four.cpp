class Solution {
public:
    bool isPowerOfFour(int n) {
        string s = bitset<64> (n).to_string();
        if(n==1)
            return true;
        if(s[s.size()-1]=='1' || n<=0 || __builtin_popcount(n)>1)
            return false;
        int count=0;
        cout<<s<<endl;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]=='1')
                break;
            if(s[i]=='0')
                count++;
        }
        cout<<count;
        return count%2==0;
    }
};