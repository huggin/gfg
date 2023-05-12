//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  int subClock(int num1, int num2) {
    // code here
    return (num1 % 12 + 12 - num2 % 12) % 12;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int num1, num2;

    cin >> num1 >> num2;

    Solution ob;
    cout << ob.subClock(num1, num2) << endl;
  }
  return 0;
}
// } Driver Code Ends
