//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
public:
  // Function to find maximum of each subarray of size k.
  vector<int> max_of_subarrays(int *arr, int n, int k) {
    // your code here
    deque<int> Q;
    for (int i = 0; i < k; ++i) {
      while (!Q.empty() && arr[Q.back()] < arr[i]) {
        Q.pop_back();
      }
      Q.push_back(i);
    }
    vector<int> ans;
    ans.push_back(arr[Q.front()]);

    for (int i = k; i < n; ++i) {
      while (Q.front() == i - k) {
        Q.pop_front();
      }
      if (!Q.empty() && arr[Q.back()] < arr[i]) {
        Q.pop_back();
      }
      Q.push_back(i);
      ans.push_back(arr[Q.front()]);
    }
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++)
      cin >> arr[i];
    Solution ob;
    vector<int> res = ob.max_of_subarrays(arr, n, k);
    for (int i = 0; i < res.size(); i++)
      cout << res[i] << " ";
    cout << endl;
  }

  return 0;
}
// } Driver Code Ends
