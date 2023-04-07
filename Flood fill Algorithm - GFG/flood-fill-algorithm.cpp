//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // void dfs(vector<vector<int>>& image,int i,int j, int oc, int nc)
    // {
    //     if(i<0 || i==image.size() || j<0 || j==image[0].size())
    //     return;
    //     if(image[i][j]!=oc)
    //     return;
    //     image[i][j]=nc;
    //     dfs(image,i,j-1,oc,nc);
    //     dfs(image,i,j+1,oc,nc);
    //     dfs(image,i-1,j,oc,nc);
    //     dfs(image,i+1,j,oc,nc);
    // }
    // vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int nc) {
    //     // Code here
    //     int oc=image[sc][sr];
    //     if(oc==nc)
    //     return image;
    //     dfs(image,sc,sr,oc,nc);
    //     return image;
    // }
        void fill(vector<vector<int>>& image, int x, int y, int color, int oldColor,int n, int m)
    {
        if(x<0 || y<0 || x==n || y==m || image[x][y]!=oldColor) return;
        image[x][y]=color;
        fill(image,x,y+1,color,oldColor,n,m);
        fill(image,x+1,y,color,oldColor,n,m);
        fill(image,x,y-1,color,oldColor,n,m);
        fill(image,x-1,y,color,oldColor,n,m);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor=image[sr][sc];
        if(color==oldColor) return image; //IMP else infinite recursive call
        fill(image,sr,sc,color,oldColor,image.size(),image[0].size());
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends