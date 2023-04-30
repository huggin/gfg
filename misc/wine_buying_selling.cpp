//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  long long int wineSelling(vector<int> &Arr, int N) {
    // Code here.
    long long ans = 0;
    for (int i = 0, j = 0; i < N && j < N;) {
      while (i < N && Arr[i] >= 0) {
        ++i;
      }
      while (j < N && Arr[j] <= 0) {
        ++j;
      }
      if (i == N || j == N)
        break;
      if (-Arr[i] <= Arr[j]) {
        ans += (static_cast<long long>(-Arr[i])) * abs(j - i);
        Arr[j] += Arr[i];
        Arr[i] = 0;
        ++i;
      } else {
        ans += (static_cast<long long>(Arr[j])) * abs(j - i);
        Arr[i] += Arr[j];
        Arr[j] = 0;
        ++j;
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
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    Solution ob;
    long long int ans = ob.wineSelling(arr, n);

    cout << ans << endl;
  }
}
// } Driver Code Ends
