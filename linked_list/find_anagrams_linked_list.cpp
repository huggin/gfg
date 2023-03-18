//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
  char data;
  struct Node *next;

  Node(char x) {
    data = x;
    next = NULL;
  }
};

void printList(Node *node) {
  while (node != NULL) {
    cout << node->data << " ";
    node = node->next;
  }
  cout << endl;
}

struct Node *inputList() {
  int n;  // length of link list
  scanf("%d ", &n);

  char data;
  cin >> data;
  struct Node *head = new Node(data);
  struct Node *tail = head;
  for (int i = 0; i < n - 1; ++i) {
    cin >> data;
    tail->next = new Node(data);
    tail = tail->next;
  }
  return head;
}

// } Driver Code Ends
/*

Definition for singly Link List Node
struct Node
{
    char data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

You can also use the following for printing the link list.
printList(Node* node);
*/

class Solution {
 public:
  vector<Node *> findAnagrams(struct Node *head, string s) {
    // code here
    Node *q = head;
    Node *p = head;
    int cnt[26] = {0};
    int n = s.size();
    for (int i = 0; i < n; ++i) {
      cnt[s[i] - 'a']++;
    }

    int cnt2[26] = {0};
    int i = 0;
    while (p && i++ < n) {
      cnt2[p->data - 'a']++;
      p = p->next;
    }

    vector<Node *> ans;
    do {
      if (!memcmp(cnt, cnt2, sizeof(cnt))) {
        ans.push_back(q);
        memset(cnt2, 0, sizeof(cnt2));

        for (i = 0; i < n - 1; ++i) {
          q = q->next;
        }
        q->next = NULL;
        q = p;
        i = 0;
        while (p && i++ < n) {
          cnt2[p->data - 'a']++;
          p = p->next;
        }
        if (i < n) break;
      } else {
        cnt2[q->data - 'a']--;
        q = q->next;
        if (!p) break;
        cnt2[p->data - 'a']++;
        p = p->next;
      }
    } while (true);

    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    struct Node *head = inputList();

    string s;
    cin >> s;

    Solution obj;
    vector<Node *> res = obj.findAnagrams(head, s);

    for (int i = 0; i < res.size(); i++) {
      printList(res[i]);
    }

    if (res.size() == 0) cout << "-1\n";
  }
}

// } Driver Code Ends
