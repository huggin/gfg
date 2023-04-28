//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  vector<int> maxProductSubsequence(int *arr, int n) {
    // Complete the function
    vector<int> left(n), right(n);
    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; --i) {
      right[i] = max(right[i + 1], arr[i]);
    }

    set<int> s;
    for (int i = 0; i < n; ++i) {
      auto it = s.lower_bound(arr[i]);
      if (it == s.begin()) {
        left[i] = -1;
      } else {
        --it;
        left[i] = *it;
      }
      s.insert(arr[i]);
    }

    long long val = -1;
    vector<int> ans(3);
    for (int i = 1; i < n - 1; ++i) {
      if (arr[i] < right[i + 1] and
          val < 1LL * left[i] * arr[i] * right[i + 1]) {
        ans[0] = left[i];
        ans[1] = arr[i];
        ans[2] = right[i + 1];
        val = 1LL * left[i] * arr[i] * right[i + 1];
      }
    }
    return val == -1 ? vector<int>{-1} : ans;
  }
};

//{ Driver Code Starts.
// Driver Program
int main() {
  int T;
  cin >> T;
  while (T--) {

    int num;
    cin >> num;
    int arr[num];
    for (int i = 0; i < num; ++i)
      cin >> arr[i];

    vector<int> res;
    Solution obj;
    res = obj.maxProductSubsequence(arr, num);

    if (res[0] == -1)
      cout << "Not Present\n";
    else {
      for (int i = 0; i < 3; ++i)
        cout << res[i] << " ";
      cout << "\n";
    }
  }
}

// } Driver Code Ends
