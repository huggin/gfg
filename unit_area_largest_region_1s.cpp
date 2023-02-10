//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    int t = 0;
    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> v(n, vector<int>(m));
        int ans = 0;
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if (grid[i][j] == 1 && !v[i][j]) {
                    t = 0;
                    queue<int> Q;
                    Q.push(i);
                    Q.push(j);
                    v[i][j] = 1;
                    while(!Q.empty()) {
                        int x = Q.front();
                        Q.pop();
                        int y = Q.front();
                        Q.pop();
                        //cout << x << ' '<< y << endl;
                        ++t;
                        for(int k = 0; k < 8; ++k) {
                            int nx = x + dx[k];
                            int ny = y + dy[k];
                            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] && !v[nx][ny]) {
                                v[nx][ny] = 1;
                                Q.push(nx);
                                Q.push(ny);
                            }
                        }
                    }
                    ans = max(ans, t);
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
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
