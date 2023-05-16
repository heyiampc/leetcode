//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    using ll=long long;
    bool fun(int i,int n,vector<int> &arr,int sum,vector<vector<int>> &dp)
    {
        if(sum==0)
        return true;
        if(i>=n)
        return false;
        if(dp[i][sum]!=-1)
        return dp[i][sum];
        bool take=false;
        if(arr[i]<=sum)
        take=fun(i+1,n,arr,sum-arr[i],dp);
        bool not_take=fun(i+1,n,arr,sum,dp);
        return dp[i][sum]=take || not_take;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return fun(0,arr.size(),arr,sum,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends