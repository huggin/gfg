//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int common_divisor(int a, int b);

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;

    cout << common_divisor(a, b) << endl;
  }

  return 0;
}
// } Driver Code Ends

int common_divisor(int a, int b) {
  // Complete the function
  if (a > b)
    swap(a, b);
  int ans = 0;
  for (int i = 1; i * i <= a; ++i) {
    if (a % i == 0) {
      if (b % i == 0)
        ++ans;
      if (i * i != a && b % (a / i) == 0)
        ++ans;
    }
  }
  return ans;
}
