//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  int remArray(int N, int arr[], int K) {
    // code here
    int ans = 1;
    for (int i = 0; i < N; ++i) {
      ans = ans * arr[i] % K;
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int N, K;

    cin >> N;

    int arr[N];
    for (int i = 0; i < N; i++)
      cin >> arr[i];

    cin >> K;

    Solution ob;
    cout << ob.remArray(N, arr, K) << endl;
  }
  return 0;
}
// } Driver Code Ends
