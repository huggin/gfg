//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node {
  int data;
  Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};

void print(Node *root) {
  Node *temp = root;
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }
}

// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  Node *reverse(Node *p) {
    Node *prev = NULL;
    while (p) {
      Node *next = p->next;
      p->next = prev;
      prev = p;
      p = next;
    }
    return prev;
  }

 public:
  Node *compute(Node *head) {
    // your code goes here
    if (!head) return NULL;
    head = reverse(head);
    int ma = head->data;
    Node *ans = head;
    Node *prev = head;
    Node *p = head->next;
    while (p) {
      if (p->data < ma) {
        Node *n = p->next;
        prev->next = p->next;
        p = n;
      } else {
        ma = max(ma, p->data);
        prev = p;
        p = p->next;
      }
    }
    ans = reverse(ans);
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int T;
  cin >> T;

  while (T--) {
    int K;
    cin >> K;
    struct Node *head = NULL;
    struct Node *temp = head;

    for (int i = 0; i < K; i++) {
      int data;
      cin >> data;
      if (head == NULL)
        head = temp = new Node(data);
      else {
        temp->next = new Node(data);
        temp = temp->next;
      }
    }
    Solution ob;
    Node *result = ob.compute(head);
    print(result);
    cout << endl;
  }
}

// } Driver Code Ends
