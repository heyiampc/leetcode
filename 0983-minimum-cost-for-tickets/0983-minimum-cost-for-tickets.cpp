class Solution {
public:
    int fun(vector<int>& days, vector<int>& costs, vector<int> &dp, int ind)
    {
        //Base Case
        if(ind>=days.size())
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        //One Day Pass
        int oneday=costs[0]+fun(days,costs,dp,ind+1);
        // Seven Day Pass
        int i;
        for(i=ind;i<days.size() && days[i]< days[ind]+7 ;i++);
        int sevenday=costs[1]+fun(days,costs,dp,i);
        //One Month
        for(i=ind;i<days.size()  && days[i]<days[ind]+30 ;i++);
        int onemonth=costs[2]+fun(days,costs,dp,i);
        return dp[ind]=min(oneday,min(sevenday,onemonth));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size()+1,-1);
        return fun(days,costs,dp,0);
    }
};