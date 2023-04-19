//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// #include <algorithm>

// } Driver Code Ends
class Solution {
public:
  // arr: input array
  // n: size of array
  // Function to sort the array into a wave-like array.
  void convertToWave(int n, vector<int> &arr) {
    // Your code here
    bool f = true;
    for (int i = 0; i < n - 1; ++i) {
      if (f) {
        if (arr[i] < arr[i + 1]) {
          swap(arr[i], arr[i + 1]);
        }
      } else {
        if (arr[i] > arr[i + 1]) {
          swap(arr[i], arr[i + 1]);
        }
      }
      f = !f;
    }
  }
};

//{ Driver Code Starts.

int main() {
  int t, n;
  cin >> t;   // Input testcases
  while (t--) // While testcases exist
  {
    cin >> n;         // input size of array
    vector<int> a(n); // declare vector of size n
    for (int i = 0; i < n; i++)
      cin >> a[i]; // input elements of array
    Solution ob;
    ob.convertToWave(n, a);

    for (int i = 0; i < n; i++)
      cout << a[i] << " "; // print array

    cout << endl;
  }
}
// } Driver Code Ends
