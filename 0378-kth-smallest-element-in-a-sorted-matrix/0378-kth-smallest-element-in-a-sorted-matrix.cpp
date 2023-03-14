class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        for(auto &x:matrix)
            for(auto &j:x)
            {
                pq.push(j);
                if(pq.size()>k)
                    pq.pop();

            }
        return pq.top();
    }
};