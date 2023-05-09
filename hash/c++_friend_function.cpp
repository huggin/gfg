//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class student {
private:
  string first_name;
  string last_name;

public:
  void set_name(string f, string l) {
    first_name = f;
    last_name = l;
  }

  friend void check_name(student k);
};

// } Driver Code Ends
// User function Template for C++

void check_name(student k) {
  // Add your code here.
  if (k.first_name.size() != k.last_name.size()) {
    cout << "NOT ANAGRAM\n";
    return;
  }
  unordered_map<int, int> m;
  for (char c : k.first_name)
    m[c]++;

  for (char c : k.last_name) {
    if (--m[c] < 0) {
      cout << "NOT ANAGRAM\n";
      return;
    }
  }
  cout << "ANAGRAM\n";
}

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {

    string f, l;
    cin >> f >> l;

    student s1;
    s1.set_name(f, l);
    check_name(s1);
  }
  return 0;
}
// } Driver Code Ends
