    public static  Node insert(Node head,int data) {
        if(head == null){
            Node newNode = new Node(data);
            return newNode;
        }
        
        
        Node returnValue = head;
        while(head.next != null){
            head = head.next;
        }
        Node newNode = new Node(data);
        head.next = newNode;
        return returnValue;
        
    }
