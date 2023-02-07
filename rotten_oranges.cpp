//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        queue<tuple<int, int, int>> Q;
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> v(n, vector<int>(m));

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) {
                    Q.emplace(i, j, 0);
                    v[i][j] = 1;
                }
            }
        }
        int ans = -1;
        int dx[] = {-1, 0, 0, 1};
        int dy[] = {0, -1, 1, 0};
        while (!Q.empty()) {
            auto c = Q.front();
            Q.pop();
            ans = max(ans, get<2>(c));
            for(int i = 0; i < 4; ++i) {
                int x = get<0>(c) + dx[i];
                int y = get<1>(c) + dy[i];
                if (x >= 0 && x < n && y >= 0 && y < m && v[x][y] == 0 && grid[x][y] == 1) {
                    v[x][y] = 1;
                    grid[x][y] = 2;
                    Q.emplace(x, y, get<2>(c) + 1);
                }
            }
        }
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) return -1;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
