class comp
{
    public:
    bool operator()(const string &a,const string &b)
    {
        return a.size()<b.size();
    }
};
class Solution {
public:
    int dp[1001][1001];
    bool check(string &t,string &s)
    { //isSubsequence
        //cout<<s<<" "<<t<<endl;
        if(t.size()!=s.size()+1)
            return false;
        int i=0;
        int j=0;
        while(i< s.size() && j<t.size())
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else
                j++;
        }
        if(i==s.size()){ //cout<<"Y"<<endl;
            return true;
        }
        return false;
    }
    int lis(int i,vector<string> &words,int prev)
    {
        if(i>=words.size())
            return 0;
        if(dp[i][prev+1]!=-1)
            return dp[i][prev+1];
        int take=0;
        if(prev==-1 || check(words[i],words[prev]))
            take=1+lis(i+1,words,i);
        int not_take=0+lis(i+1,words,prev);
        return dp[i][prev+1]=max(take,not_take);
    }
    int longestStrChain(vector<string>& words) {
        memset(dp,-1,sizeof(dp));
        sort(words.begin(),words.end(),comp());
        // for(auto &x:words)
        //     cout<<x<<" ";
        return lis(0,words,-1);
    }
};