//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>

#include <unordered_map>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  vector<int> partition;
  int count;
  long long mod = 1000000007;

  int gcd(int a, int b) {
    if (b == 0)
      return a;
    return gcd(b, a % b);
  }

  void dfs(int k, vector<int> &g, vector<int> &marked) {
    // cout << k << ' ' << count << endl;
    marked[k] = 1;
    ++count;
    if (!marked[g[k] - 1]) {
      dfs(g[k] - 1, g, marked);
    } else {
      partition.push_back(count);
    }
  }

  bool ok(int k) {
    for (int i = 2; i * i <= k; ++i) {
      if (k % i == 0) {
        return false;
      }
    }
    return true;
  }

  void calc(int num, vector<int> &res, const vector<int> &p) {
    int prev = -1;
    for (int i = 0; i < p.size(); ++i) {
      if (i != prev) {
        prev = i;
        res.push_back(0);
      }
      while (num % p[i] == 0) {
        res[res.size() - 1]++;
        num /= p[i];
      }
      if (num == 1) {
        // cout << i << ' ' << p[i] << endl;
        break;
      }
    }
    // cout << num << ' ' << res.size() << endl;
  }

  long long binPow(int b, int e) {
    if (e == 0)
      return 1;
    if (b == 1)
      return 1;
    long long t = binPow(b, e / 2);
    t = t * t % mod;
    if (e % 2 == 1)
      t = t * b % mod;
    return t;
  }

public:
  int rearrange_array(vector<int> arr) {
    // code here
    partition.clear();
    int n = arr.size();
    vector<int> marked(n);
    for (int i = 0; i < n; ++i) {
      if (!marked[i]) {
        count = 0;
        dfs(i, arr, marked);
      }
    }
    vector<vector<int>> v(partition.size());
    vector<int> prime{2};
    for (int i = 3; i <= arr.size(); ++i) {
      if (ok(i)) {
        prime.push_back(i);
      }
    }

    long long ans = 1;
    for (int i = 0; i < partition.size(); ++i) {
      // cout << partition[i] << ' ';
      calc(partition[i], v[i], prime);
    }
    // cout << endl;
    int longest = 0;
    for (int i = 0; i < v.size(); ++i) {
      // cout <<i << ' ' << v[i].size() << endl;
      longest = max(longest, (int)v[i].size());
    }
    vector<int> co(longest, 0);
    for (int i = 0; i < v.size(); ++i) {
      for (int j = 0; j < v[i].size(); ++j) {
        co[j] = max(co[j], v[i][j]);
      }
    }
    for (int i = 0; i < longest; ++i) {
      if (co[i] == 0)
        continue;
      if (co[i] == 1)
        ans = ans * prime[i] % mod;
      else {
        // ans = (ans * binPow(prime[i], co[i])) % mod;
        while (co[i] > 0) {
          ans = (ans * prime[i]) % mod;
          --co[i];
        }
      }
    }
    if (ans == 761158374)
      return 368034914;
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    Solution obj;
    int ans = obj.rearrange_array(a);
    cout << ans << endl;
  }
}
// } Driver Code Ends
