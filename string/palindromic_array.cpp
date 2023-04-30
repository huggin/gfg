//{ Driver Code Starts
#include <string.h>

#include <iostream>
using namespace std;

// } Driver Code Ends
/*Complete the function below*/
#include <sstream>

class Solution {
  bool isPalindrome(int a) {
    stringstream ss;
    ss << a;
    string s;
    ss >> s;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
      if (s[i] != s[n - 1 - i])
        return false;
    }
    return true;
  }

public:
  int PalinArray(int a[], int n) {
    // code here
    for (int i = 0; i < n; ++i) {
      if (!isPalindrome(a[i]))
        return 0;
    }
    return 1;
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
    for (int i = 0; i < n; i++)
      cin >> a[i];
    Solution obj;
    cout << obj.PalinArray(a, n) << endl;
  }
}
// } Driver Code Ends
