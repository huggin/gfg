//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++
class Solution {
  bool prime(int k) {
    for (int i = 2; i * i <= k; ++i) {
      if (k % i == 0) return false;
    }
    return true;
  }

  bool ok(int a, int b) {
    // cout << a << ' ' << b << ' ';
    int ans = 0;
    for (int i = 0; i < 4; ++i) {
      int k1 = a % 10;
      int k2 = b % 10;
      if (k1 != k2) ++ans;
      a = a / 10;
      b = b / 10;
    }
    // cout << bool(ans == 1) << endl;
    return ans == 1;
  }

 public:
  int solve(int Num1, int Num2) {
    // code here
    vector<int> a;
    int src = -1, des = -1;
    for (int i = 1000; i <= 9999; ++i) {
      if (prime(i)) {
        a.push_back(i);
        if (i == Num1) src = a.size() - 1;
        if (i == Num2) des = a.size() - 1;
        // cout << i << endl;
      }
    }
    int n = a.size();
    // cout << n << endl;
    vector<int> v(n);
    vector<int> dist(n, -1);
    v[src] = 1;
    queue<int> Q;
    Q.push(src);
    Q.push(0);
    while (!Q.empty()) {
      int c = Q.front();
      Q.pop();
      int step = Q.front();
      Q.pop();
      dist[c] = step;
      for (int i = 0; i < n; ++i) {
        if (!v[i] && ok(a[c], a[i])) {
          // cout << a[i] << ' ' << a[c] << endl;
          v[i] = 1;
          Q.push(i);
          Q.push(step + 1);
        }
      }
    }
    if (!dist[des]) return -1;
    return dist[des];
  }
};

//{ Driver Code Starts.
signed main() {
  int t;
  cin >> t;
  while (t--) {
    int Num1, Num2;
    cin >> Num1 >> Num2;
    Solution obj;
    int answer = obj.solve(Num1, Num2);
    cout << answer << endl;
  }
}
// } Driver Code Ends
