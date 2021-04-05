/**
 * Definition for binary tree with next pointer.
 * public class TreeLinkNode {
 *     int val;
 *     TreeLinkNode left, right, next;
 *     TreeLinkNode(int x) { val = x; }
 * }
 */
public class Solution {
	public void connect(TreeLinkNode root) {
		if (root == null) {
			return;
		}
		LinkedList<TreeLinkNode> q = new LinkedList<TreeLinkNode>();
		LinkedList<TreeLinkNode> children = new LinkedList<TreeLinkNode>();
		q.add(root);
		while (!q.isEmpty()) {
			TreeLinkNode node = q.removeFirst();
			if (node.left != null) {
				children.add(node.left);
			}
			if (node.right != null) {
				children.add(node.right);
			}
			if (q.isEmpty()) {
				q = children;
				children = new LinkedList<TreeLinkNode>();
			} else {
				node.next = q.peekFirst();
			}
		}
	}
}
