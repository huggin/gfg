//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class SortedStack {
public:
  stack<int> s;
  void sort();
};

void printStack(stack<int> s) {
  while (!s.empty()) {
    printf("%d ", s.top());
    s.pop();
  }
  printf("\n");
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    SortedStack *ss = new SortedStack();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int k;
      cin >> k;
      ss->s.push(k);
    }
    ss->sort();
    printStack(ss->s);
  }
}
// } Driver Code Ends

/*The structure of the class is
class SortedStack{
public:
        stack<int> s;
        void sort();
};
*/

void gsort(stack<int> &s) {
  if (s.empty())
    return;
  int temp = s.top();
  s.pop();
  gsort(s);
  vector<int> vi;
  while (!s.empty() && s.top() > temp) {
    vi.push_back(s.top());
    s.pop();
  }
  s.push(temp);
  for (int i = vi.size() - 1; i >= 0; --i)
    s.push(vi[i]);
}

/* The below method sorts the stack s
you are required to complete the below method */
void SortedStack ::sort() {
  // Your code here
  gsort(s);
}
