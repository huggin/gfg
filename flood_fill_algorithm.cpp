//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        vector<vector<int>> ans(image);
        if (image[sr][sc] == newColor) return ans;
        int oldColor = image[sr][sc];
        int dx[] = {0, 1, -1, 0};
        int dy[] = {-1, 0, 0, 1};
        queue<int> Q;
        Q.push(sr);
        Q.push(sc);
        ans[sr][sc] = newColor;
        while(!Q.empty()) {
            int x= Q.front();
            Q.pop();
            int y = Q.front();
            Q.pop();
            for(int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < ans.size() && ny >=0 && ny < ans[0].size()
                    && ans[nx][ny] == oldColor) {
                        
                    ans[nx][ny] = newColor;
                    Q.push(nx);
                    Q.push(ny);
                }
            }
        }
        return ans;
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
