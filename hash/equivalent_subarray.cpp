//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  int countDistinctSubarray(int arr[], int n) {
    // code here.
    unordered_set<int> s;
    for (int i = 0; i < n; ++i) {
      s.insert(arr[i]);
    }
    int sz = s.size();
    int ans = 0;
    unordered_map<int, int> m;
    int cnt = 0;
    int j = 0;
    for (int i = 0; i < n; ++i) {
      if (m[arr[i]]++ == 0) {
        if (++cnt == sz) {
          ans += n - i;
          while (--m[arr[j]] > 0) {
            ans += n - i;
            ++j;
          }
          ++j;
          --cnt;
        }
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
    int a[n];
    for (int i = 0; i < n; ++i)
      cin >> a[i];
    Solution ob;
    cout << ob.countDistinctSubarray(a, n) << endl;
  }
  return 0;
}
// } Driver Code Ends
