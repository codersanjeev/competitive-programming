#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
   public:
    int data;
    SinglyLinkedListNode* next;

    SinglyLinkedListNode(int node_data) {
        this->data = node_data;
        this->next = nullptr;
    }
};

class SinglyLinkedList {
   public:
    SinglyLinkedListNode* head;
    SinglyLinkedListNode* tail;

    SinglyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insert_node(int node_data) {
        SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

        if (!this->head) {
            this->head = node;
        } else {
            this->tail->next = node;
        }

        this->tail = node;
    }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the findMergeNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

int findLength(SinglyLinkedListNode* l) {
    int ans = 0;
    while (l != NULL) {
        ans += 1;
        l = l->next;
    }
    return ans;
}

int getIntersection(SinglyLinkedListNode* l1, SinglyLinkedListNode* l2, int d) {
    while (d != 0) {
        l1 = l1->next;
        d--;
    }
    if (l1 == l2)
        return l1->data;

    while (l1 != NULL && l2 != NULL) {
        if (l1 == l2)
            return l1->data;
        l1 = l1->next;
        l2 = l2->next;
    }
    return 0;
}

int findMergeNode(SinglyLinkedListNode* l1, SinglyLinkedListNode* l2) {
    int x = findLength(l1);
    int y = findLength(l2);
    if (x == 0 || y == 0)
        return 0;
    if (x > y)
        return getIntersection(l1, l2, x - y);
    else
        return getIntersection(l2, l1, y - x);
}

int main()