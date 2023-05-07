//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution {
public:
  int binaryPalin(long long int N) {
    // Your Code Here
    vector<int> v;
    while (N) {
      v.push_back(N % 2);
      N /= 2;
    }
    for (int i = 0; i < v.size() / 2; ++i)
      if (v[i] != v[v.size() - 1 - i])
        return false;

    return true;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    Solution ob;
    cout << ob.binaryPalin(n) << endl;
  }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
