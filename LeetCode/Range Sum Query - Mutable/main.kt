class SegmentTree(nums: IntArray) {
    private var treeSize = 1
    private var tree: LongArray

    init {
        while (this.treeSize < nums.size) {
            this.treeSize = this.treeSize.shl(1)
        }
        this.tree = LongArray(this.treeSize.shl(1))
        this.build(nums, 0, 0, this.treeSize)
    }

    private fun build(nums: IntArray, x: Int, lx: Int, rx: Int) {
        if (rx - lx == 1) {
            if (lx < nums.size) this.tree[x] = nums[lx].toLong()
            return
        }
        val mx = lx + (rx - lx).shr(1)
        build(nums, x.shl(1) + 1, lx, mx)
        build(nums, x.shl(1) + 2, mx, rx)
        this.tree[x] = this.tree[x.shl(1) + 1] + this.tree[x.shl(1) + 2]
    }

    private fun update(i: Int, v: Int, x: Int, lx: Int, rx: Int) {
        if (rx - lx == 1) {
            this.tree[x] = v.toLong()
            return
        }
        val mx = lx + (rx - lx).shr(1)
        if (i < mx) {
            update(i, v, x.shl(1) + 1, lx, mx)
        } else {
            update(i, v, x.shl(1) + 2, mx, rx)
        }
        this.tree[x] = this.tree[x.shl(1) + 1] + this.tree[x.shl(1) + 2]
    }

    private fun query(l: Int, r: Int, x: Int, lx: Int, rx: Int): Long {
        if (lx >= r || rx <= l) return 0L
        if (lx >= l && rx <= r) return tree[x]
        val mx = lx + (rx - lx).shr(1)
        return query(l, r, x.shl(1) + 1, lx, mx) + query(l, r, x.shl(1) + 2, mx, rx)
    }

    fun update(i: Int, v: Int) = update(i, v, 0, 0, this.treeSize)

    fun query(left: Int, right: Int) = query(left, right, 0, 0, this.treeSize)
}

class NumArray(nums: IntArray) {
    private var tree = SegmentTree(nums)

    fun update(i: Int, v: Int) = tree.update(i, v)

    fun sumRange(left: Int, right: Int) = tree.query(left, right + 1).toInt()
}

