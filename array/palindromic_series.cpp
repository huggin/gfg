//{ Driver Code Starts
#include <bits/stdc++.h>

#include <string>

using namespace std;

bool pallan(int n);

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    if (pallan(n))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
// } Driver Code Ends

bool pallan(int n) {
  // Complete the function
  vector<int> v;
  int cnt = 0;
  while (n) {
    cnt += n % 10;
    v.push_back(n % 10);
    n /= 10;
  }
  reverse(v.begin(), v.end());
  v.reserve(cnt);
  int k = 0;
  while (v.size() < cnt) {
    v.push_back(v[k++]);
  }
  for (int i = 0; i < cnt / 2; ++i) {
    if (v[i] != v[cnt - 1 - i]) return false;
  }
  return true;
}
