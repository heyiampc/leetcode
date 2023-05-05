class Solution {
public:
    bool isvowel(char a)
    {
        if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u')
            return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int vcount=0;
        int n=s.size();
        for(int i=0;i<k;i++)
        {
            if(isvowel(s[i]))
                vcount++;
        }
        if(vcount==k)
            return k;
        int maxi=vcount;
        string temp=s.substr(0,k);
        // cout<<temp<<endl;
        for(int i=k;i<n;i++)
        {
            if(isvowel(s[i]))
            {
                vcount++;
            }
            if(isvowel(temp[0]))
            {
                vcount--;
            }
            temp.erase(0,1);
            temp+=s[i];
            // cout<<temp<<endl;
            maxi=max(maxi,vcount);
        }
        return maxi;
    }
};