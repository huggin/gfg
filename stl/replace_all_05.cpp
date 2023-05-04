//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Driver program to test above function

// } Driver Code Ends
class Solution {
public:
  /*you are required to complete this method*/
  int convertFive(int n) {
    // Your code here
    stringstream ss;
    ss << n;
    string s;
    ss >> s;
    replace(begin(s), end(s), '0', '5');
    return atoi(s.c_str());
  }
};

//{ Driver Code Starts.
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    Solution obj;
    cout << obj.convertFive(n) << endl;
  }
}
// } Driver Code Ends
