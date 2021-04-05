class SparseVector {
   public:
    SparseVector(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                mp[i] = nums[i];
            }
        }
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& nums) {
        auto A = nums.mp;
        auto B = this->mp;
        int ans = 0;
        for (const auto& ele : A) {
            if (B[ele.first] != 0) {
                ans += (ele.second * B[ele.first]);
            }
        }
        return ans;
    }

   private:
    unordered_map<int, int> mp;
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);