//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    int findShortestPath(vector<vector<int>> &mat)
    {
       // code here
        int n = mat.size(); 
        int m = mat[0].size();
        vector<int> pos;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if (mat[i][j] == 0) {
                    pos.push_back(i);
                    pos.push_back(j);
                }
            }
        }
        int dx[] = {-1, 0, 0, 1};
        int dy[] = {0, -1, 1, 0};
        for(int i = 0; i < pos.size(); i+=2) {
            for(int k = 0; k < 4; ++k) {
                int nx = pos[i] + dx[k];
                int ny = pos[i+1] + dy[k];
                if (nx >= 0 && nx < n && ny >=0 && ny < m) {
                    mat[nx][ny] = 0;
                }
            }
        }
        
        vector<vector<int>> v(n, vector<int>(m));
        queue<int> Q;
        for(int j = 0; j < n; ++j) {
            if (mat[j][0] == 1) {
                Q.push(j);
                Q.push(0);
                Q.push(1);
                v[j][0] = 1;
            }
        }
        while(!Q.empty()) {
            int x = Q.front();
            Q.pop();
            int y = Q.front();
            Q.pop();
            int d = Q.front();
            Q.pop();
            //cout << x << ' ' << y << ' ' << d << endl;
            if (y == m-1) return d;
            for(int k = 0; k < 4; ++k) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny] && !v[nx][ny]) {
                    v[nx][ny] = 1;
                    Q.push(nx);
                    Q.push(ny);
                    Q.push(d+1);
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> mat(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        int ans = ob.findShortestPath(mat);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
