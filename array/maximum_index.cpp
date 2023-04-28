//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  // A[]: input array
  // N: size of array
  // Function to find the maximum index difference.
  int maxIndexDiff(int A[], int N) {
    // Your code here
    vector<int> dp(N);
    dp[0] = 0;
    for (int i = 1; i < N; ++i) {
      dp[i] = i;
      if (A[i] >= A[i - 1]) {
        for (int j = 0; j <= dp[i - 1]; ++j) {
          if (A[i] >= A[j]) {
            dp[i] = j;
            break;
          }
        }
      } else {
        for (int j = dp[i - 1]; j < i; ++j) {
          if (A[i] >= A[j]) {
            dp[i] = j;
            break;
          }
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < N; ++i) {
      ans = max(i - dp[i], ans);
    }

    return ans;
  }
};

//{ Driver Code Starts.

/* Driver program to test above functions */
int main() {
  int T;
  // testcases
  cin >> T;
  while (T--) {
    int num;
    // size of array
    cin >> num;
    int arr[num];

    // inserting elements
    for (int i = 0; i < num; i++)
      cin >> arr[i];
    Solution ob;

    // calling maxIndexDiff() function
    cout << ob.maxIndexDiff(arr, num) << endl;
  }
  return 0;
}
// } Driver Code Ends
