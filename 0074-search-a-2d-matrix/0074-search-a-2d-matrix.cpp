class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool ans=false;
        for(auto mat:matrix)
            ans|=binary_search(mat.begin(),mat.end(),target);
        return ans;
    }
};