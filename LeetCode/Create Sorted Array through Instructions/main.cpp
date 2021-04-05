#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")

auto speedup = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return nullptr;
}();

struct BIT {
	int N;
	vector<int> arr;
	vector<int> bit;

	void init(const vector<int> &A) {
		arr = A;
		int n = arr.size();
		N = n + 1;
		bit.resize(N);
		for (int i = 0; i < arr.size(); i++) {
			addElement(i, arr[i]);
		}
	}

	int prefixSum(int index) {
		int answer = 0;
		index++;
		while (index > 0) {
			answer += bit[index];
			index -= (index & -index);
		}
		return answer;
	}

	int rangeSum(int L, int R) {
		return prefixSum(R) - prefixSum(L - 1);
	}

	void addElement(int index, int delta) {
		index++;
		while (index < N) {
			bit[index] += delta;
			index += (index & -index);
		}
	}

	void updateElement(int index, int element) {
		int delta = element - arr[index];
		arr[index] = element;
		addElement(index, delta);
	}
};

class Solution {
  public:
	const int mod = 1e9 + 7;
	const int N = 1e5 + 1;
	int createSortedArray(vector<int> &arr) {
		BIT *bit = new BIT();
		bit->init(vector<int>(N, 0));
		int ans = 0;
		for (int i = 0; i < arr.size(); i++) {
			int ele = arr[i];
			ans = (ans + min(bit->prefixSum(ele - 1), i - bit->prefixSum(ele))) % mod;
			bit->addElement(ele, 1);
		}
		return ans;
	}
};