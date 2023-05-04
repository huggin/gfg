//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n, int x) {
  // code here
  auto p = equal_range(arr, arr + n, x);
  if (p.first == arr + n || *p.first != x) {
    return vector<int>{-1, -1};
  }
  vector<int> ans{(int)(p.first - arr), (int)(p.second - arr - 1)};
  return ans;
}

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    int arr[n], i;
    for (i = 0; i < n; i++)
      cin >> arr[i];
    vector<int> ans;
    ans = find(arr, n, x);
    cout << ans[0] << " " << ans[1] << endl;
  }
  return 0;
}

// } Driver Code Ends
