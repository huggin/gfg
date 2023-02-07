    int n, m;
    pair<int, int> solve(vector<int>& v) {
        unordered_map<int, int> s;
        int t = 0;
        int left = -1, right = -1;
        int len = 0;
        s[0] = -1;
        for(int i = 0; i < m; ++i) {
            t += v[i];
            if (s.find(t) == s.end()) {
                s[t] = i;
            } else {
                if (len < i - s[t]) {
                    left = s[t]+1;
                    right = i;
                    len = i - s[t];
                }
            }
        }
        return make_pair(left, right);
    }
public:
    vector<vector<int>> sumZeroMatrix(vector<vector<int>> a){
        //Code Here
        n = a.size(); 
        m = a[0].size();
        int area = -1;
        
        int up = -1, down = -1, left = -1, right = -1;
        vector<vector<int>> v(a);
        
        for(int i = 0; i < n; ++i) {
            auto c = solve(v[i]);
            if (c.first == -1) continue;
            if (area == -1 || area < (c.second - c.first + 1) 
                || area == c.second - c.first + 1 && c.first < left) {
                area = c.second - c.first + 1;
                up = down = i;
                left = c.first;
                right = c.second;
                //cout << c.first << ' ' << c.second << ' ' << up << endl;
            }
        }
        for(int k = 1; k < n; ++k) {
            for(int j = 0; j < n-k; ++j) {
                for(int i = 0; i < m; ++i) {
                    v[j][i] += a[j+k][i];
                }
                auto c = solve(v[j]);
                if (c.first == -1) continue;
                if (area == -1 || area < (k + 1) * (c.second - c.first + 1)
                    || (area == (k + 1) * (c.second - c.first + 1) && c.first < left)
                    || (area == (k + 1) * (c.second - c.first + 1) && c.first < left && j < up)) {
                    //cout << c.first << ' ' << c.second << ' ' << k + 1 << endl;
                    up = j;
                    down = j + k;
                    left = c.first;
                    right = c.second;
                    area = (k + 1) * (c.second - c.first + 1);
                }
            }
        }
        //cout << area << endl;
        if (area == -1) return vector<vector<int>>{};
        vector<vector<int>> ans(down-up+1);
        for(int i=up; i<=down; ++i) {
            for(int j=left; j<=right; ++j) {
                ans[i-up].push_back(a[i][j]);
            }
        }
        return ans;
