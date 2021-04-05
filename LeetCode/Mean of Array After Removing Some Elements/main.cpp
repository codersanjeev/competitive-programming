class Solution {
public:
    double trimMean(vector<int>& arr) {
        int n = arr.size(), total = accumulate(arr.begin(), arr.end(), 0), rem = n / 20;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < rem; i++) {
        	total -= arr[i];
        	total -= arr[n - 1 - i];
        }
        return (total * 1.0) / (n - rem - rem);
    }
};