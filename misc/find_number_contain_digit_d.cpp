//{ Driver Code Starts
// CPP program to print the number which
// contain the digit d from 0 to n
#include <bits/stdc++.h>
using namespace std;
vector<int> solve(int n, int d);

int main() {
  int t, n, d;
  cin >> t;
  while (t--) {
    cin >> n >> d;
    vector<int> v = solve(n, d);
    for (auto it : v) cout << it << " ";
    cout << endl;
  }

  return 0;
}

// } Driver Code Ends

bool contain(int i, int d) {
  if (i == 0 && d == 0) return true;
  while (i) {
    if (i % 10 == d) return true;
    i /= 10;
  }
  return false;
}

vector<int> solve(int n, int d) {
  // code here
  vector<int> ans;
  for (int i = 0; i <= n; ++i) {
    if (contain(i, d)) ans.push_back(i);
  }
  if (ans.empty()) return vector<int>{-1};
  return ans;
}
