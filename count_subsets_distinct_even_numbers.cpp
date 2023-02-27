//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
#define ll long long

long long countSubsets(int a[], int n);

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << countSubsets(a, n) << endl;
  }

  return 0;
}
// } Driver Code Ends

// User function Template for C++

long long countSubsets(int a[], int n) {
  vector<int> cnt(1001);
  for (int i = 0; i < n; ++i) {
    cnt[a[i]] = 1;
  }
  long long ans = 1;
  for (int i = 2; i <= 1000; i += 2) {
    if (cnt[i]) ans *= cnt[i] + 1;
  }
  return ans - 1;
}
