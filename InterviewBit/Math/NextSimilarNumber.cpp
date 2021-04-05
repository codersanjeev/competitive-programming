string Solution::solve(string nums) {
    int n = nums.size(), index = n - 2;
    if (n == 1) {
        return "-1";
    }
    while (index >= 0 && nums[index] >= nums[index + 1]) {
        index--;
    }
    if (index < 0) {
        return "-1";
    }
    int indexTwo = n - 1;
    while (nums[index] >= nums[indexTwo]) {
        indexTwo--;
    }
    swap(nums[index], nums[indexTwo]);
    int lo = index + 1, hi = n - 1;
    while (lo < hi) {
        swap(nums[lo], nums[hi]);
        lo++;
        hi--;
    }
    return nums;
}
