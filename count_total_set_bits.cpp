//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
  // n: input to count the number of set bits
  // Function to return sum of count of set bits in the integers from 1 to n.
  int countSetBits(int n) {
    // Your logic here
    unordered_map<int, int> m;
    m[0] = 0;
    m[1] = 1;
    m[2] = 2;
    int k = 2;
    for (int i = 4; i <= n; i *= 2) {
      m[i] = k * (i / 2) + 1;
      ++k;
    }
    int i = 1;
    for (; i * 2 <= n; i *= 2)
      ;
    // cout << "i = " << i << endl;
    int ans = 0;
    for (int j = i; j > 0; j /= 2) {
      // cout << j << endl;
      if (j <= n) {
        ans += m[j];
        n -= j;
        ans += n;
      }
    }

    return ans;
  }
};

//{ Driver Code Starts.

// Driver code
int main() {
  int t;
  cin >> t;    // input testcases
  while (t--)  // while testcases exist
  {
    int n;
    cin >> n;  // input n
    Solution ob;
    cout << ob.countSetBits(n) << endl;  // print the answer
  }
  return 0;
}

// } Driver Code Ends
