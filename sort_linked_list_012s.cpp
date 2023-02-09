//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        Node* c = head;
        Node* new_head = NULL, *prev_zero = NULL;
        Node* one_head = NULL, *prev_one = NULL;
        Node* two_head = NULL, *prev_two = NULL;
        while(c) {
            if (c->data == 0) {
                if (!new_head) {
                    new_head = c;
                } else {
                    prev_zero->next = c;
                }
                prev_zero = c;
            } else if (c->data == 2) {
                if (!two_head) {
                    two_head = c;
                } else {
                    prev_two->next = c;
                }
                prev_two = c;
            } else {
                if (!one_head) {
                    one_head = c;
                } else {
                    prev_one->next = c;
                }
                prev_one = c;
            }
            c = c->next;
        }
        if (prev_zero) {
            prev_zero->next = NULL;
        }
        if (prev_one) {
            prev_one->next = NULL;
        }
        if (prev_two) {
            prev_two->next = NULL;
        }
        if (new_head == NULL) {
            if (one_head == NULL) {
                new_head = two_head;
            } else {
                new_head = one_head;
            }
        }
        if (prev_zero) {
            if (one_head) {
                prev_zero->next = one_head;
            } else {
                prev_zero->next = two_head;
            }
        }
        if (prev_one) {
            prev_one->next = two_head;
        }
        return new_head;
    }
};

//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends
