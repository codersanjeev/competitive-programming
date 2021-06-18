class FindSumPairs {
   private:
    vector<int> X, Y;
    map<int, int> mp;

   public:
    FindSumPairs(vector<int> &nums1, vector<int> &nums2) {
        X = nums1;
        Y = nums2;
        for (const auto &ele : nums2) mp[ele]++;
    }

    void add(int index, int val) {
        int oldValue = Y[index];
        Y[index] += val;
        int newValue = Y[index];
        mp[oldValue] -= 1;
        mp[newValue] += 1;
    }

    int count(int target) {
        int answer = 0;
        for (const auto &ele : X) {
            answer += mp[target - ele];
        }
        return answer;
    }
};