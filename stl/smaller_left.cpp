//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<int> Smallestonleft(int arr[], int n);

int main() {

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n + 1];

    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    vector<int> b;
    b = Smallestonleft(arr, n);
    for (int i = 0; i < n; i++)
      cout << b[i] << " ";

    cout << endl;
  }

  return 0;
}
// } Driver Code Ends

vector<int> Smallestonleft(int arr[], int n) {
  // Complete the function
  set<int> s;
  vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    if (s.empty()) {
      ans[i] = -1;
    } else {
      auto it = s.lower_bound(arr[i]);
      --it;
      if (it != s.end() && *it < arr[i])
        ans[i] = *it;
      else
        ans[i] = -1;
    }
    s.insert(arr[i]);
  }
  return ans;
}
