class Solution {
  public:
	int shipWithinDays(vector<int>& weights, int D) {
		int lo = *max_element(weights.begin(), weights.end()), hi = accumulate(weights.begin(), weights.end(), 0), ans = 0;
		while (lo <= hi) {
			int mid = lo + (hi - lo) / 2;
			if (canShip(weights, D, mid)) {
				ans = mid;
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}
		return ans;
	}

	bool canShip(const vector<int> &weights, int days, int capacity) {
		int currWeight = 0, requiredDays = 1;
		for (const auto &ele : weights) {
			if (ele + currWeight > capacity) {
				requiredDays++;
				currWeight = ele;
			} else {
				currWeight += ele;
			}
		}
		return requiredDays <= days;
	}

};