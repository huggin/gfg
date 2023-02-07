//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

int visited[51][51][2501];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

class Solution {
  public:
    int shotestPath(vector<vector<int>> mat, int n, int m, int k) {
        // code here
        memset(visited, 0, sizeof(visited));
        priority_queue<
            tuple<int, int, int, int>, 
            vector<tuple<int, int, int, int>>, 
            greater<tuple<int, int, int, int>>> Q;
        
        int oo = 100000000;
        Q.push(make_tuple(0, 0, 0, 0));
        visited[0][0][0] = 1;
        while(!Q.empty()) {
            auto c = Q.top();
            Q.pop();
            int i = get<2>(c); 
            int j = get<3>(c);
            int dist = get<0>(c);
            int b = get<1>(c);
            if (dist >= oo || b > k) return -1;
            for(int l = 0; l < 4; ++l) {
                int x = i + dx[l];
                int y = j + dy[l];
                if (x < 0 || x >= mat.size() || y < 0 || y >= mat[0].size())
                    continue;
                bool f = false;
                for(int ii=0; ii<=b; ++ii) {
                    if (visited[x][y][ii] == 1) {
                        f = true;
                        break;
                    }
                }
                if (f) continue;
                if (x == mat.size() - 1 && y == mat[0].size() - 1) return dist + 1;
                if (mat[x][y] == 0) {
                    visited[x][y][b] = 1;
                    Q.push(make_tuple(dist+1, b, x, y));
                } else {
                    if (b < k) {
                        visited[x][y][b+1] = 1;
                        Q.push(make_tuple(dist+1, b+1, x, y));
                    } else {
                        visited[x][y][b+1] = 1;
                        Q.push(make_tuple(oo, b+1, x, y));
                    }
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k, x;
        
        cin>>n>>m>>k;
        vector<vector<int>> mat;
    
        for(int i=0; i<n; i++)
        {
            vector<int> row;
            for(int j=0; j<m; j++)
            {
                cin>>x;
                row.push_back(x);
            }
            mat.push_back(row);
        }

        Solution ob;
        cout<<ob.shotestPath(mat,n,m,k);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
