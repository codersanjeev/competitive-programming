	public static int getHeight(Node root){
      int heightLeft = 0;
    int heightRight = 0;

    if (root.left != null) {
        heightLeft = getHeight(root.left) + 1;
    }
    if (root.right != null) {
        heightRight = getHeight(root.right) + 1;
    }

  return (heightLeft > heightRight ? heightLeft : heightRight);
    }
