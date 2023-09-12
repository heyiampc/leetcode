class Solution {
public:
    void print(vector<int> &vec)
    {
        for(auto &x:vec)
            cout<<x<<" ";
        cout<<endl;
    }
int makeElementsUnique(vector<int>& arr) {
    unordered_map<int, int> frequency;
    int operations = 0;
    for (int num : arr) {
        if (frequency.find(num) != frequency.end()) {
            while (frequency.find(num) != frequency.end() && frequency[num] > 0) {
                num--;
                operations++;
            }
        }
        if (num > 0) {
            frequency[num]++;
        }
    }

    return operations;
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
        int ans=makeElementsUnique(vec);
        return ans;
    }
};