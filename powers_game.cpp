//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

vector<int> getFreq(int x, int n);

int main() {
  int t;
  cin >> t;
  while (t--) {
    int x, n;
    cin >> x >> n;
    auto ans = getFreq(x, n);
    for (auto &x : ans) {
      cout << x << " ";
    }
    cout << "\n";
  }
  return 0;
}

// } Driver Code Ends

vector<int> getFreq(int x, int n) {
  // code here
  vector<int> ans(10);
  for (int i = 1; i <= n; ++i) {
    long long k = powl(x, i);
    while (k) {
      ++ans[k % 10];
      k /= 10;
    }
  }
  return ans;
}
