class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<long long> v(60);
        for(auto x:time)
        {
            v[x%60]+=1;
        }
        long long count=0;
        count+=((v[0]-1)*v[0])/2;
        count+=((v[30]-1)*v[30])/2;
        for(int i=1;i<=29;i++)
        {
            count+=v[i]*v[60-i];
        }
        return count;
    }
};