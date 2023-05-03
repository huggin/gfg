//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  vector<int> prime;

  void sieve(long long n) {
    long long k = sqrt(n);
    vector<int> num(k + 1, 1);
    num[0] = num[1] = 0;
    for (int i = 2; i < k + 1; ++i) {
      if (num[i] == 1) {
        prime.push_back(i);
        for (int j = i * i; j < k + 1; j += i) {
          num[j] = 0;
        }
      }
    }
  }

public:
  long long int nineDivisors(long long int N) {
    // Code Here
    sieve(N);
    int n = prime.size();

    long long ans = 0;
    for (int i = 0; i < sqrt(n); ++i) {
      long long k = 1;
      for (int j = 0; j < 8; ++j) {
        k *= prime[i];
        if (k > N)
          break;
      }
      if (k <= N) {
        ++ans;
      }
      for (int j = i + 1; j < n; ++j) {
        long long d = prime[i] * prime[j];
        if (d * d <= N) {
          ++ans;
        } else {
          break;
        }
      }
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int N;
    cin >> N;
    Solution ob;
    cout << ob.nineDivisors(N) << endl;
  }
  return 0;
}
// } Driver Code Ends
