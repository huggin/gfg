//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

long long getSum(int[], int n);
main() {
  // your code goes here
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << getSum(a, n) << endl;
  }
  return 0;
}
// } Driver Code Ends

/*You are required to complete this method */
long long getSum(int A[], int n) {
  // Your code here
  const int M = 1e9 + 7;
  long long d = 1;
  for (int i = 1; i < n; ++i) d = (d * i) % M;
  d = (accumulate(A, A + n, 0LL) * d) % M;

  long long ans = 0;
  int p = 1;
  for (int i = 0; i < n; ++i) {
    ans = (ans + p * d) % M;
    p = (p * 10) % M;
  }

  return ans;
}
