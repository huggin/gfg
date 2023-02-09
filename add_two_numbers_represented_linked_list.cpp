//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    Node* reverse(Node *p) {
        Node *prev = NULL;
        while(p) {
            Node* next = p->next;
            p->next = prev;
            prev = p;
            p = next;
        }
        return prev;
    }
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        first = reverse(first);
        second = reverse(second);
        int more = 0;
        Node* ans = NULL;
        Node* prev = NULL;
        while(first && second) {
            int t = first->data + second->data + more;
            if (t >= 10) {
                t -= 10;
                more = 1;
            } else {
                more = 0;
            }
            if (!prev) {
                ans = new Node(t);
                prev = ans;
            } else {
                prev->next = new Node(t);
                prev = prev->next;
            }
            first = first->next;
            second = second->next;
        }
        //return ans;

        if (second != NULL) {
            first = second;
        }
        while(first) {
            int t = first->data + more;
            if (t >= 10) {
                t -= 10;
                more = 1;
            } else {
                more = 0;
            }
            if (!prev) {
                ans = new Node(t);
                prev = ans;
            } else {
                prev->next = new Node(t);
                prev = prev->next;
            }
            first = first->next;
        }
        if (more) {
            if (!prev) {
                ans = new Node(1);
                prev = ans;
            } else {
                prev->next = new Node(1);
                prev = prev->next;
            }
        }
        ans = reverse(ans);
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends
