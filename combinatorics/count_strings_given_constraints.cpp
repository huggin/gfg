//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int countStr(long long int n);

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    cout << countStr(n) << endl;
  }
  return 0;
}
// } Driver Code Ends

long long int countStr(long long int n) {
  // complete the function here
  long long ans = 0;
  ans += 1;                         // no c no b
  ans += n;                         // 1 b, no c
  ans += n;                         // 1 c, no b
  ans += n * (n - 1) / 2;           // 2c, no b
  ans += n * (n - 1);               // 1c, 1b
  ans += n * (n - 1) * (n - 2) / 2; // 2c 1b
  return ans;
}
