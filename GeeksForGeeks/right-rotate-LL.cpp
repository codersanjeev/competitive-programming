// { Driver Code Starts
#include <bits/stdc++.h>
#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node *rotate(struct Node *head, int k);

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        head = rotate(head,k);
        printList(head);
    }
    return 1;
}
// } Driver Code Ends


/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

// This function should rotate list counter-clockwise
// by k and return new head (if changed)
Node* rotate(Node* head, int k) {
    if (head == NULL) return head;
    Node* i = head;
    // count nodes
    int n=0;
    while (i!=NULL) {
    	n++; i=i->next;
    }
    cout << "n: "<<n<<"_ ";
    
    if (k>=n) return head;
    
    i=head;
    k=n-k-1;
    while (k--) {
        i=i->next;
    }
    // head = i;
    Node* j = i->next;
    while (j->next!=NULL) {
        j=j->next;
    }
    j->next=head;
    head = i->next;
    i->next=NULL;
    return head;
}
