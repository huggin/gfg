//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
 public:
  vector<int> sixyPrime(int L, int R) {
    // code here
    vector<char> is_prime(R + 1, 1);
    is_prime[0] = is_prime[1] = 0;
    vector<int> prime;
    for (int i = 2; i <= R; ++i) {
      if (is_prime[i]) {
        if (i >= L) prime.push_back(i);
        for (int j = i * i; j <= R; j += i) is_prime[j] = 0;
      }
    }
    vector<int> ans;
    for (int i = 0; i < prime.size(); ++i) {
      for (int j = i + 1; j < prime.size(); ++j) {
        if (prime[j] == prime[i] + 6) {
          ans.push_back(prime[i]);
          ans.push_back(prime[j]);
          break;
        }
      }
    }
    if (ans.empty()) return vector<int>{-1};
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int L, R;
    cin >> L >> R;
    Solution ob;
    vector<int> ans = ob.sixyPrime(L, R);
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << endl;
  }
  return 0;
}

// } Driver Code Ends
