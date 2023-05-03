//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  vector<int> primeRange(int N, int Q, vector<int> A,
                         vector<pair<int, int>> R) {
    // code here
    int ma = *max_element(A.begin(), A.end());
    vector<bool> prime(ma + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= ma; ++i) {
      if (prime[i]) {
        for (int j = i * i; j <= ma; j += i)
          prime[j] = false;
      }
    }

    vector<int> sum(N);
    sum[0] = prime[A[0]] ? 1 : 0;
    for (int i = 1; i < N; ++i) {
      if (prime[A[i]])
        sum[i] = sum[i - 1] + 1;
      else
        sum[i] = sum[i - 1];
    }
    vector<int> ans;
    for (auto c : R) {
      if (c.first > c.second)
        ans.push_back(0);
      else if (c.first == 1)
        ans.push_back(sum[c.second - 1]);
      else
        ans.push_back(sum[c.second - 1] - sum[c.first - 2]);
    }
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    vector<pair<int, int>> R(Q);
    for (int i = 0; i < N; i++)
      cin >> A[i];
    for (int i = 0; i < Q; i++)
      cin >> R[i].first >> R[i].second;
    Solution ob;
    vector<int> ans = ob.primeRange(N, Q, A, R);
    for (auto u : ans)
      cout << u << " ";
    cout << "\n";
  }
}
// } Driver Code Ends
