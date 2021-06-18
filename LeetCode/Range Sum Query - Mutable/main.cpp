class SegmentTree {
   private:
    vector<long> tree;
    long treeSize;

    void build(const vector<long>& nums, long x, long lx, long rx) {
        if (rx - lx == 1) {
            if (lx < nums.size()) this->tree[x] = nums[lx];
            return;
        }
        long mx = lx + ((rx - lx) >> 1);
        build(nums, (x << 1) + 1, lx, mx);
        build(nums, (x << 1) + 2, mx, rx);
        this->tree[x] = this->tree[(x << 1) + 1] + this->tree[(x << 1) + 2];
    }

    void update(long i, long v, long x, long lx, long rx) {
        if (rx - lx == 1) {
            this->tree[x] = v;
            return;
        }
        long mx = lx + ((rx - lx) >> 1);
        if (i < mx) {
            update(i, v, (x << 1) + 1, lx, mx);
        } else {
            update(i, v, (x << 1) + 2, mx, rx);
        }
        this->tree[x] = this->tree[(x << 1) + 1] + this->tree[(x << 1) + 2];
    }

    long query(long l, long r, long x, long lx, long rx) {
        if (lx >= r || rx <= l) return 0;
        if (lx >= l && rx <= r) return this->tree[x];
        long mx = lx + ((rx - lx) >> 1);
        return query(l, r, (x << 1) + 1, lx, mx) + query(l, r, (x << 1) + 2, mx, rx);
    }

   public:
    SegmentTree(const vector<long>& nums) {
        this->treeSize = 1;
        while (this->treeSize < nums.size()) {
            this->treeSize <<= 1;
        }
        this->tree.resize(this->treeSize << 1, 0);
        this->build(nums, 0, 0, this->treeSize);
    }

    void update(long index, long val) {
        update(index, val, 0, 0, this->treeSize);
    }

    long query(long left, long right) {
        return query(left, right, 0, 0, this->treeSize);
    }
};

class NumArray {
   private:
    SegmentTree* tree;

   public:
    NumArray(vector<int>& arr) {
        vector<long> nums;
        for (const auto& ele : arr) nums.push_back((long)ele);
        tree = new SegmentTree(nums);
    }

    void update(int index, int val) {
        tree->update(index, val);
    }

    int sumRange(int left, int right) {
        return tree->query(left, right + 1);
    }
};