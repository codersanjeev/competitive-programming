// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
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



bool isPalindrome(Node *head);
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
	cin>>T;
	while(T--)
	{
		
		struct Node *head = NULL,  *tail = NULL;
		cin>>n;
		// taking first data of LL
		cin>>firstdata;
		head = new Node(firstdata);
		tail = head;
		// taking remaining data of LL
		for(i=1;i<n;i++)
		{
			cin>>l;
			tail->next = new Node(l);
			tail = tail->next;
		}
   	cout<<isPalindrome(head)<<endl;
	}
	return 0;
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
/*You are required to complete this method */
bool isPalindrome(Node *head)
{
	if (head==NULL) return false;
	// one node
	if (head->next==NULL) return true;
	// two nodes
	if (head->next->next==NULL) {
		if (head->data == head->next->data) return true;
		else return false;
	}
	
	//more than 3 nodes;
	Node* slow = head;
	Node* fast = head;
	stack<int> s;
	
	while (fast->next!=NULL && fast->next->next!=NULL) {
		s.push(slow->data);
		slow = slow->next;
		fast = fast->next->next;
	}

	// if even no. of nodes, push the stack;
	if (fast->next != NULL) {
		s.push(slow->data);
	}
	
	slow = slow->next;
	while (slow != NULL) {
		if (s.top() != slow->data) return false;
		s.pop();
		slow = slow->next;
	}
	if (s.empty()) return true;
	else return false;
}

