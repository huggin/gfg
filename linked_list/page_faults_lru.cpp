//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

struct Node {
  int data;
  Node *prev;
  Node *next;
  Node(int d) : data(d), prev(NULL), next(NULL) {}
};

class Solution {
  Node *find(Node *p, int v) {
    while (p) {
      if (p->data == v)
        return p;
      p = p->next;
    }
    return NULL;
  }

public:
  int pageFaults(int N, int C, int pages[]) {
    // code here
    Node *head = new Node(-1), *last = NULL;
    int n = 0;
    int ans = 0;
    for (int i = 0; i < N; ++i) {
      Node *p = find(head->next, pages[i]);
      if (p) {
        if (p->next != NULL) {
          p->next->prev = p->prev;
        } else {
          last = p->prev;
          last->next = NULL;
        }
        p->prev->next = p->next;
        if (head->next) {
          head->next->prev = p;
        }
        p->next = head->next;
        p->prev = head;
        head->next = p;
        if (last == head)
          last = p;
      } else {
        ++ans;

        p = new Node(pages[i]);
        if (head->next) {
          head->next->prev = p;
          p->next = head->next;
        } else {
          last = p;
        }
        p->prev = head;
        head->next = p;
        if (++n > C) {
          last = last->prev;
          last->next = NULL;
          n = C;
        }
      }
    }
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int N, C;
    cin >> N;
    int pages[N];
    for (int i = 0; i < N; i++)
      cin >> pages[i];
    cin >> C;

    Solution ob;
    cout << ob.pageFaults(N, C, pages) << "\n";
  }
  return 0;
}
// } Driver Code Ends
