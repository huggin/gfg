//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    vector<vector<char>> b;
    string w;
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    int n, m;
    int v[101][101];
    
    bool solve(int i, int j, int k) {
        if (b[i][j] == w[k]) {
            if (k == w.size() - 1) return true;
            for(int ii = 0; ii< 4; ++ii) {
                int ni = i + dx[ii];
                int nj = j + dy[ii];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m 
                    && v[ni][nj] == 0) {
                        v[ni][nj] = 1;
                        if (solve(ni, nj, k+1)) return true;
                        v[ni][nj] = 0;
                    }
            }
        }
        return false;
    }
public:
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        b = board;
        w = word;
        n = b.size();
        m = b[0].size();
        for(int i = 0; i < b.size(); ++i) {
            for(int j = 0; j < b[i].size(); ++j) {
                if (b[i][j] == word[0]) {
                    memset(v, 0, sizeof(v));
                    v[i][j] = 1;
                    if (solve(i, j, 0)) return 1;
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends
