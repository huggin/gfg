//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  int maximizeSum(int a[], int n) {
    // Complete the function
    multiset<int> s(a, a + n);
    int ans = 0;
    while (!s.empty()) {
      auto it = s.rbegin();
      ans += *it;
      int d = *it - 1;
      ++it;
      s.erase(it.base());
      auto it2 = s.find(d);
      if (it2 != s.end())
        s.erase(it2);
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
    int arr[n];

    for (int i = 0; i < n; i++)
      cin >> arr[i];
    sort(arr, arr + n);
    Solution ob;

    cout << ob.maximizeSum(arr, n) << endl;
  }
}

// } Driver Code Ends
