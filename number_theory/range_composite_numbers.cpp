//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
bool prime[1500000];
void sieve() {
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= 1499999; p++) {
    if (prime[p] == true) {
      for (int i = p * 2; i <= 1499999; i += p)
        prime[i] = false;
    }
  }
}
vector<long> range(int n);
int main() {
  sieve();
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long> a = range(n);
    if (a.size() == n) {
      int flag = 1;
      if (prime[a[0]] == true) {
        flag = 0;
      }
      for (int i = 1; i < n; i++) {
        if (prime[a[i]] == true) {
          flag = 0;
        }
        if (a[i - 1] + 1 != a[i]) {
          flag = 0;
        }
      }
      if (flag == 1) {
        cout << "1\n";
      } else {
        cout << "0\n";
      }
    } else {
      cout << "0\n";
    }
  }
}
// } Driver Code Ends

/*Complete the function below*/
vector<long> range(int n) {
  // add code here.
  vector<long> ans;
  ans.reserve(n);
  for (long i = 4;; ++i) {
    if (ans.size() == n)
      break;
    if (!prime[i]) {
      ans.push_back(i);
    } else {
      ans.clear();
    }
  }
  return ans;
}
