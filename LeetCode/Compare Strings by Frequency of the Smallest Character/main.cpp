class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int n = words.size();
        vector<int> wordsFreq(n, 0);
        for (int i = 0; i < n; i++) {
        	wordsFreq[i] = f(words[i]);
        }
        sort(wordsFreq.begin(), wordsFreq.end());
        vector<int> ans;
        for (const auto &ele : queries) {
        	int curr = f(ele), cnt = 0;
        	cnt = findCountUtil(wordsFreq, curr);
        	ans.push_back(cnt);
        }
        return ans;
    }
private:
	int f(const string &s) {
		int ans = 0;
		char ch = *min_element(s.begin(), s.end());
		for (const auto &ele : s) {
			if (ele == ch) {
				ans++;
			}
		}
		return ans;
	}

	int findCountUtil(const vector<int> &arr, int ele) {
		int lo = 0, hi = arr.size() - 1, ans = 0;
		while (lo <= hi) {
			int mid = lo + (hi - lo) / 2;
			if (arr[mid] > ele) {
				ans = arr.size() - mid;
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}
		return ans;
	}
};