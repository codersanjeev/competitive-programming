class SegmentTree {
	private var treeSize: Int
	private var tree: [Int]
	
	init(_ nums: [Int]) {
		self.treeSize = 1
		while self.treeSize < nums.count {
			self.treeSize <<= 1
		}
		tree = [Int](repeating: 0, count: self.treeSize << 1)
		build(nums, 0, 0, self.treeSize)
	}
	
	private func build(_ nums: [Int], _ x: Int, _ lx: Int, _ rx: Int) {
		if rx - lx == 1 {
			if lx < nums.count {
				self.tree[x] = nums[lx]
			}
			return
		}
		let mx = lx + (rx - lx) >> 1
		build(nums, (x << 1) + 1, lx, mx)
		build(nums, (x << 1) + 2, mx, rx)
		self.tree[x] = self.tree[(x << 1) + 1] + self.tree[(x << 1) + 2]
	}
	
	private func update(_ i: Int, _ v: Int, _ x: Int, _ lx: Int, _ rx: Int) {
		if rx - lx == 1 {
			self.tree[x] = v
			return
		}
		let mx = lx + (rx - lx) >> 1
		if i < mx {
			update(i, v, (x << 1) + 1, lx, mx)
		} else {
			update(i, v, (x << 1) + 2, mx, rx)
		}
		tree[x] = tree[(x << 1) + 1] + tree[(x << 1) + 2]
	}
	
	private func query(_ l: Int, _ r: Int, _ x: Int, _ lx: Int, _ rx: Int) -> Int {
		if lx >= r || rx <= l { return 0 }
		if lx >= l && rx <= r { return tree[x] }
		let mx = lx + (rx - lx) >> 1
		return query(l, r, (x << 1) + 1, lx, mx) + query(l, r, (x << 1) + 2, mx, rx)
	}
	
	func update(index i: Int, val v: Int) {
		update(i, v, 0, 0, self.treeSize)
	}
	
	func query(left l: Int, right r: Int) -> Int {
		return query(l, r, 0, 0, self.treeSize)
	}
	
}

class NumArray {
	private var tree: SegmentTree
	
	init(_ nums: [Int]) {
		self.tree = SegmentTree(nums)
	}
	
	func update(_ index: Int, _ val: Int) {
		tree.update(index: index, val: val)
	}
	
	func sumRange(_ left: Int, _ right: Int) -> Int {
		return tree.query(left: left, right: right + 1)
	}
}
