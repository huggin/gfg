//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
  long long findMinSum(vector<int>& A, vector<int>& B, int N) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int ans =
        transform_reduce(begin(A), end(A), begin(B), 0, std::plus<>{},
                         [](const int& a, const int& b) { return abs(a - b); });
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
      cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
      cin >> B[i];
    }
    Solution ob;
    cout << ob.findMinSum(A, B, N) << endl;
  }
}
// } Driver Code Ends
