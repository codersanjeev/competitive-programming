/*
Detect a cycle in a linked list. Note that the head pointer may be 'null' if the list is empty.

A Node is defined as: 
    class Node {
        int data;
        Node next;
    }
*/

boolean hasCycle(Node h) {
    HashSet<Node> s = new HashSet<Node>();
        while (h != null)
        {
             // If we have already has this node
             // in hashmap it means their is a cycle
             // (Because you we encountering the
             // node second time).
            if (s.contains(h))
                return true;
   
            // If we are seeing the node for
            // the first time, insert it in hash
            s.add(h);
   
            h = h.next;
        }
   
        return false;
}
