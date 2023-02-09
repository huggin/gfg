class Solution{
    vector<string> ans;
    string s;
    int n;
    vector<vector<int>> b;
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    char d[4] = {'U', 'L', 'R', 'D'};
    int v[6][6];
    
    void solve(int i, int j) {
        if (i == n-1 && j == n-1) {
            ans.push_back(s);
            return;
        }
        for(int k = 0; k < 4; ++k) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (ni >= 0 && ni < n && nj >= 0 && nj < n && b[ni][nj] == 1 && v[ni][nj] == 0) {
                v[ni][nj] = 1;
                s += d[k];
                solve(ni, nj);
                v[ni][nj] = 0;
                s.pop_back();
            }
        }
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int N) {
        // Your code goes here
        n = N;
        ans.clear();
        if (m[0][0] == 0) return ans;
        s.clear();
        b = m;
        memset(v, 0, sizeof(v));
        v[0][0] = 1;
        
        solve(0, 0);
        return ans;
    }
};

