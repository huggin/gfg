//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  vector<int> parent;
  vector<int> count;

  int find(int i) {
    while (i != parent[i]) {
      parent[i] = parent[parent[i]];
      i = parent[i];
    }
    return i;
  }

  int merge(int i, int j) {
    if (count[i] < count[j]) {
      parent[i] = j;
      count[j] += count[i];
      return j;
    } else {
      parent[j] = i;
      count[i] += count[j];
      return i;
    }
  }

public:
  vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
    // code here
    count.assign(n * m, 1);
    parent.assign(n * m, -1);
    for (int i = 0; i < n * m; ++i)
      parent[i] = i;

    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, -1, 1, 0};

    vector<vector<int>> b(n, vector<int>(m));

    int t = 0;
    vector<int> ans;
    for (auto &e : operators) {
      int x = e[0];
      int y = e[1];
      if (b[x][y] == 1) {
        ans.push_back(t);
        continue;
      }
      b[x][y] = 1;
      int p1 = x * m + y;
      vector<int> r;
      for (int k = 0; k < 4; ++k) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || !b[nx][ny])
          continue;
        int p2 = nx * m + ny;
        r.push_back(p2);
      }

      if (r.size() == 0) {
        ans.push_back(++t);
      } else {
        while (r.size() >= 2) {
          int t1 = find(r.back());
          r.pop_back();
          int t2 = find(r.back());

          r.pop_back();
          if (t1 != t2) {
            --t;
            t1 = merge(t1, t2);
          }
          r.push_back(t1);
        }
        merge(find(p1), find(r.back()));
        ans.push_back(t);
      }
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a;

    for (int i = 0; i < k; i++) {
      vector<int> temp;
      for (int j = 0; j < 2; j++) {
        int x;
        cin >> x;
        temp.push_back(x);
      }
      a.push_back(temp);
    }

    Solution obj;
    vector<int> res = obj.numOfIslands(n, m, a);

    for (auto x : res)
      cout << x << " ";
    cout << "\n";
  }
}

// } Driver Code Ends
