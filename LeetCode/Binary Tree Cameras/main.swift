
class Solution {
	private var cameraCount = 0
	
	private enum TreeNodeState {
		case HAS_CAMERA, COVERED, NOT_COVERED
	}
	
	private func cover(_ root: TreeNode?) -> TreeNodeState {
		guard let root = root else { return TreeNodeState.COVERED }
		let left = cover(root.left)
		let right = cover(root.right)
		if (left == TreeNodeState.NOT_COVERED || right == TreeNodeState.NOT_COVERED) {
			cameraCount += 1
			return TreeNodeState.HAS_CAMERA
		}
		if (left == TreeNodeState.HAS_CAMERA || right == TreeNodeState.HAS_CAMERA) {
			return TreeNodeState.COVERED
		} else {
			return TreeNodeState.NOT_COVERED
		}
	}
	
	func minCameraCover(_ root: TreeNode?) -> Int {
		return cover(root) == TreeNodeState.NOT_COVERED ? cameraCount + 1 : cameraCount
	}
}
