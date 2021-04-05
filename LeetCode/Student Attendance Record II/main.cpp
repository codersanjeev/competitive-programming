class Solution {
  public:
	int checkRecord(int n) {
		return (checkRecordUtil(1, n, "A", 1) + checkRecordUtil(1, n, "L", 0) + checkRecordUtil(1, n, "P", 0)) % mod;
	}

  private:

	int _cache[100001][2][12] = {0};
	unordered_map<string, int> indexMap;
	int cnt = -1;
	const int mod = 1e9 + 7;

	long checkRecordUtil(int index, int n, string previous, int numberOfATaken) {
		if (index == n) {
			return 1;
		}
		long l = 0, a = 0, p = 0;
		if (indexMap.find(previous) == indexMap.end()) {
			cnt++;
			indexMap[previous] = cnt;
		}
		int k = indexMap[previous];
		if (_cache[index][numberOfATaken][k] != 0) {
			return _cache[index][numberOfATaken][k];
		}
		if (previous != "LL") {
			l = checkRecordUtil(index + 1, n, getStringUtil(previous, "L"), numberOfATaken);
		}
		if (numberOfATaken == 0) {
			a = checkRecordUtil(index + 1, n, getStringUtil(previous, "A"), numberOfATaken + 1);
		}
		p = checkRecordUtil(index + 1, n, getStringUtil(previous, "P"), numberOfATaken);
		return _cache[index][numberOfATaken][k] = (l + a + p) % mod;
	}

	string getStringUtil(const string &s, const string &t) {
		int n = s.size();
		return s[n - 1] + t;
	}

};