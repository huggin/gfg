//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int val;
  Node *next;
  Node(int num) {
    val = num;
    next = NULL;
  }
};

// } Driver Code Ends
// User function Template for C++

/*

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

*/

class Solution {
  vector<int> isPrime;

  void seive() {
    isPrime[0] = isPrime[1] = 0;

    for (int i = 2; i <= 10100; ++i) {
      if (isPrime[i] == 1) {
        for (int j = 2 * i; j <= 10100; j += i) isPrime[j] = 0;
      }
    }
  }

  pair<int, int> find(int v) {
    pair<int, int> ans;
    int i;
    for (i = v; !isPrime[i]; ++i)
      ;
    ans.first = i;
    for (i = v; !isPrime[i]; --i)
      ;
    ans.second = i;
    return ans;
  }

 public:
  Node *primeList(Node *head) {
    isPrime.assign(10101, 1);
    seive();
    Node *p = head;
    while (p) {
      auto a = find(p->val);
      if (a.first - p->val >= p->val - a.second)
        p->val = a.second;
      else
        p->val = a.first;
      p = p->next;
    }
    return head;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    Node *head, *tail;
    int num;
    cin >> num;
    head = tail = new Node(num);
    for (int i = 0; i < n - 1; i++) {
      int num;
      cin >> num;
      tail->next = new Node(num);
      tail = tail->next;
    }
    Solution ob;
    Node *temp = ob.primeList(head);
    while (temp != NULL) {
      cout << temp->val << " ";
      temp = temp->next;
    }
    cout << endl;
  }
  return 0;
}
// } Driver Code Ends
