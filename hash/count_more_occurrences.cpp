//{ Driver Code Starts
// A C++ program to print elements with count more than n/k

#include <bits/stdc++.h>

#include <iostream>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  // Function to find all elements in array that appear more than n/k times.
  int countOccurence(int arr[], int n, int k) {
    // Your code here
    int ans = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < n; ++i) {
      ++m[arr[i]];
    }
    for (auto c : m) {
      if (c.second > n * 1.0 / k) {
        ++ans;
      }
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t, k;
  cin >> t;
  while (t--) {
    int n, i;
    cin >> n;

    int arr[n];

    for (i = 0; i < n; i++)
      cin >> arr[i];
    cin >> k;
    Solution obj;
    cout << obj.countOccurence(arr, n, k) << endl;
  }
  return 0;
}

// } Driver Code Ends
