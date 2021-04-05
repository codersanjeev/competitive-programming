class Solution {
   public:
    int splitArray(vector<int> &A, int K) {
        int lo = *max_element(A.begin(), A.end()), hi = accumulate(A.begin(), A.end(), 0);
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int segments = numberOfSegments(A, mid);
            if (segments <= K) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }

    int numberOfSegments(const vector<int> &arr, int x) {
        int cnt = 1, curr = 0;
        for (const auto &ele : arr) {
            curr += ele;
            if (curr > x) {
                cnt++;
                curr = ele;
            }
        }
        return cnt;
    }
};