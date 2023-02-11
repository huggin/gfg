//{ Driver Code Starts
#include <iostream>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  int minAmount(int A[], int N) {
    // code here.
    if (N == 1) return 0;
    int dp1[N] = {0};
    int dp2[N] = {0};
    dp2[0] = A[0];
    for (int i = 1; i < N; ++i) {
      dp1[i] = dp2[i - 1];
      dp2[i] = min(dp2[i - 1], dp1[i - 1]) + A[i];
    }
    return min(dp1[N - 1], dp2[N - 1]);
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    Solution ob;
    cout << ob.minAmount(arr, n) << endl;
  }
}
// } Driver Code Ends
