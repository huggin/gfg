//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
  int count(int n) {
    int ans = 0;
    while (n) {
      n = n & (n - 1);
      ++ans;
    }
    return ans;
  }
  void sortBySetBitCount(int arr[], int n) {
    // Your code goes here
    stable_sort(arr, arr + n, [this](int x, int y) {
      return this->count(x) > this->count(y);
    });
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
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    Solution ob;
    ob.sortBySetBitCount(arr, n);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
  }
  return 0;
}

// } Driver Code Ends
