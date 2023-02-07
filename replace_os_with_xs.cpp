//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<char>> ans(mat);
        vector<vector<char>> v(n, vector<char>(m));

        queue<int> Q;
        for(int i = 0; i < n; ++i) {
            if (mat[i][0] == 'O')  {
                Q.push(i);
                Q.push(0);
                v[i][0] = 1;
            }
            if (mat[i][m-1] == 'O') {
                Q.push(i);
                Q.push(m-1);
                v[i][m-1] = 1;
            }
        }
        for(int j = 0; j < m; ++j) {
            if (mat[0][j] == 'O') { 
                Q.push(0);
                Q.push(j);
                v[0][j] = 1;
                //cout << 0 << ' ' << j << endl;
            }
            if (mat[n-1][j] == 'O') {
                Q.push(n-1);
                Q.push(j);
                v[n-1][j] = 1;
            }
        }
        int dx[] = {0, 1, -1, 0};
        int dy[] = {-1, 0, 0, 1};
        while(!Q.empty()) {
            int x = Q.front();
            Q.pop();
            int y = Q.front();
            Q.pop();
            for(int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny] == 'O' && v[nx][ny] == 0) {
                    v[nx][ny] = 1;
                    Q.push(nx);
                    Q.push(ny);
                }
            }
        }
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if (v[i][j] == 0) ans[i][j] = 'X';
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
