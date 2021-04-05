class Solution {
  public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		int i = 0, cnt = 0, N = flowerbed.size();
		while (i < N) {
			if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == N - 1 || flowerbed[i + 1] == 0)) {
				flowerbed[i++] = 1;
				cnt++;
			}
			if (cnt >= n) {
				return true;
			}
			i++;
		}
		return false;
	}
};