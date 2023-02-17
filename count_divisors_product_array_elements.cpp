//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  vector<int> prime;
  void sieve(int n) {
    vector<int> v(n, 1);
    v[0] = v[1] = 0;
    for (int i = 2; i < n; ++i) {
      if (v[i]) {
        prime.push_back(i);
        for (int j = i + i; j <= n; j += i) v[j] = 0;
      }
    }
  }

 public:
  long long int countDivisorsMult(int arr[], int n) {
    sieve(101);
    vector<int> cnt(101);
    for (int i = 0; i < n; ++i) {
      int k = arr[i];
      for (int j = 0; j < prime.size(); ++j) {
        while (k % prime[j] == 0) {
          cnt[prime[j]]++;
          k /= prime[j];
        }
      }
    }
    long long ans = 1;
    for (int i = 2; i <= 97; ++i) {
      // cout << i << ' ' << cnt[i] << endl;
      if (cnt[i]) ans *= (cnt[i] + 1);
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, i;
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++) cin >> arr[i];
    Solution obj;
    cout << obj.countDivisorsMult(arr, n) << "\n";
  }
  return 0;
}

// } Driver Code Ends
