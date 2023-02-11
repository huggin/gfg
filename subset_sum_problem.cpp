//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  vector<vector<int>> mem;
  int n;
  int* a;
  int dp(int k, int s) {
    if (s == 0) {
      return 1;
    }
    if (k == n) {
      return 0;
    }
    if (mem[k][s] != -1) {
      return mem[k][s];
    }
    int& ans = mem[k][s];
    ans = dp(k + 1, s) || (a[k] <= s) && dp(k + 1, s - a[k]);
    return ans;
  }

 public:
  bool isSubsetSum(int N, int arr[], int sum) {
    // code here
    n = N;
    a = arr;
    mem.resize(N);
    for (int i = 0; i < N; ++i) {
      mem[i].assign(sum + 1, -1);
    }
    return dp(0, sum);
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int N, sum;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
      cin >> arr[i];
    }
    cin >> sum;

    Solution ob;
    cout << ob.isSubsetSum(arr, sum) << endl;
  }
  return 0;
}

// } Driver Code Ends
