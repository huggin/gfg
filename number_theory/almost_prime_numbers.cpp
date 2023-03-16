//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

void printKAlmostPrimes(int k, int n);

int main() {
  // your code goes herei
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    printKAlmostPrimes(n, k);
    cout << endl;
  }

  return 0;
}
// } Driver Code Ends

int countPrimes(int n) {
  int ans = 0;
  for (int i = 2; i <= n; ++i) {
    while (n % i == 0) {
      ++ans;
      n /= i;
    }
  }
  return ans;
}

/*You are required to complete this function*/
void printKAlmostPrimes(int k, int n) {
  // Your code here
  for (int i = 2;; ++i) {
    if (countPrimes(i) == k) {
      cout << i;
      if (--n)
        cout << ' ';
      else
        break;
    }
  }
}
